/**
 * @defgroup  file_lists Data Units 
 * @ingroup   cfg  
 * @see       fs  
 * @brief     系统的全局数据单元描述  
 *
 * @{
 * @file
 *
 */
#include "hfp_system.h"
#include "fs.h"
#include "hfp_handy.h"
#include "relay_ctrl_plugin.h"
#include "prepay_internal.h"
#include "lib_calclib.h"

#define rly_save1 sizeof(struct relay_ctrl_state_t)
#define rly_save2 sizeof(struct relay_ctrl_info_t)
#define rly_save3 sizeof(struct relay_ctrl_result_t)

#define DEMAND_LEN         0x04
#define DEMAND_TIME_LEN    0x05
#define DEMAND_SAME        0x05
#define STATISTIC_LEN      (sizeof(struct vol_quality_t) * 5)

#define ENERGY_SAME        0x05
#define PULSE_BLOCK_LEN    2
#define KWH_BLOCK_LEN      4

#define RAM_ENERGY_SAME    0x05
#define RAM_ENERGY_LEN     0x04
#define RAM_PULSE_LEN      0x01

struct vol_quality_t
{
    uint32 statistic_times;   /**< 总检测时间 */
    uint16 ok_rate;           /**< 合格率 */
    uint16 bad_rate;          /**< 超限率 */
    uint32 vol_bad_times1;    /**< 超上限时间 */
    uint32 vol_bad_times2;    /**< 超下限时间 */
};

extern const struct hfp_device_t CODE *match_device(uint16 device_id);

/**************数据格式表格****************************************/
enum file_format_index
{   /* 注意 ：最好是 8 个一行， 中间不允许有间断 */
	format_00, format_01, format_02, format_03, format_04, format_05, format_06, format_07, /**< 00 -- 07 */
	format_08, format_09, format_10, format_11, format_12, format_13, format_14, format_15, /**< 08 -- 15 */
	format_16, format_17, format_18, format_19, format_20,
    F_U16_V_N1, F_I32_A_N3, F_U32_W_N1, F_U32_KW_N4, F_U32_KVAR_N4, F_U8_SEC_0, F_I16_PER_N1, F_I16_PER_N2, F_U16_PER_N2,
    F_ENUM, F_BOOL, F_OAD, F_I32_KWH_N2, F_I32_KVARH_N2, F_I32_KVAH_N2, F_I32_W_N1, F_I32_var_N1, F_I32_VA_N1, F_I16_COS_N3,
	F_U16_ANGLE_N1, F_U16_HZ_N2, F_U32_KWH_N2, F_U32_KVARH_N2, F_U32_KVAH_N2, 
	F_I32_KWH_N4, F_I32_KVARH_N4, F_I32_KVAH_N4, F_U32_KWH_N4, F_U32_KVARH_N4, F_U32_KVAH_N4, 
    F_U32_Ah_N2, F_ARRAY_NUDEF, F_OAD_NUDEF, F_DATETIME_S_NUDEF, F_NULL
};

const struct file_format_t CODE file_format[] =
{
    { FORM_HEX, DT_ERROR, unit_undefined, 0, format_00 }, /**< 第一行不使用 */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_W, 0, format_01 }, /**< 有功功率，W */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_var, 0, format_02 }, /**< 无功功率，var */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_VA, 0, format_03 }, /**< 视在功率，VA */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_kWh, 0, format_04 }, /**< 有功电能，kWh */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_kvarh, 0, format_05 }, /**< 无功电能，kvarh */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_kVAh, 0, format_06 }, /**< 视在电能，kVAh */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_A, 0, format_07 }, /**< 电流（I） */
    { FORM_HEX, DT_LONG_UNSIGNED, unit_V, 0, format_08 }, /**< 电压（U） */
    { FORM_HEX, DT_LONG_UNSIGNED, unit_Hz, 0, format_09 }, /**< 频率 */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_second, 0, format_10 }, /**< 秒 */
    { FORM_HEX, DT_LONG_UNSIGNED, unit_undefined, 0, format_11 }, /**< 功率因素 */
    { FORM_HEX, DT_OCTET_STRING, unit_undefined, 0, format_12 }, /**< DT_OCTET_STRING */
    { FORM_HEX, DT_BIT_STRING, unit_undefined, 0, format_13 }, /**< DT_BIT_STRING */
    { FORM_HEX, DT_STRUCTURE, unit_undefined, 0, format_14 }, /**< DT_STRUCTURE */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_undefined, 0, format_15 }, /**< DT_DOUBLE_LONG_UNSIGNED */
    { FORM_HEX, DT_INTEGER_UNSIGNED, unit_undefined, 0, format_16 }, /**< DT_INTEGER_UNSIGNED */
    { FORM_HEX, DT_PUSH_PROCESS, unit_undefined, 0, format_17 }, /**< DT_PUSH_PROCESS */
    { FORM_HEX, DT_DOUBLE_LONG, unit_W, -4, format_18 }, /**<   */
    { FORM_HEX, DT_DOUBLE_LONG, unit_var, -4, format_19 }, /**<   */
    { FORM_HEX, DT_DOUBLE_LONG, unit_VA, -4, format_20 }, /**<   */
    { FORM_HEX, DT_LONG_UNSIGNED, unit_V, -1, F_U16_V_N1 }, /**<   */
    { FORM_HEX, DT_DOUBLE_LONG, unit_A, -3, F_I32_A_N3 }, /**<   */
    { FORM_HEX, DT_DOUBLE_LONG, unit_W, -1, F_U32_W_N1 }, /**<   */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_kW, -4, F_U32_KW_N4 }, /**<   */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_kvar, -4, F_U32_KVAR_N4 }, /**<   */
    { FORM_HEX, DT_INTEGER_UNSIGNED, unit_second, 0, F_U8_SEC_0 }, /**<   */
    { FORM_HEX, DT_LONG, unit_percent, -1, F_I16_PER_N1 }, /**<   */
    { FORM_HEX, DT_LONG, unit_percent, -2, F_I16_PER_N2 }, /**<   */
    { FORM_HEX, DT_LONG_UNSIGNED, unit_percent, -2, F_U16_PER_N2 }, /**<   */
    { FORM_HEX, DT_ENUM, unit_percent, 0, F_ENUM }, /**<   */
    { FORM_HEX, DT_BOOLEAN, unit_percent, 0, F_BOOL }, /**<   */
    { FORM_HEX, DT_OAD, unit_percent, 0, F_OAD }, /**<   */
    { FORM_HEX, DT_NULL, unit_percent, 0, F_NULL }, /**<   */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_kWh, -2, F_U32_KWH_N2 }, /**< 有功电能-普通精度 */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_kvarh, -2, F_U32_KVARH_N2 }, /**< 无功电能-普通精度 */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_kVAh, -2, F_U32_KVAH_N2 }, /**< 视在电能-普通精度 */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_kWh, -4, F_U32_KWH_N4 }, /**< 有功电能-高精度 */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_kvarh, -4, F_U32_KVARH_N4 }, /**< 无功电能-高精度 */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_kVAh, -4, F_U32_KVAH_N4 }, /**< 视在电能-高精度 */
    { FORM_HEX, DT_DOUBLE_LONG, unit_kWh, -2, F_I32_KWH_N2 }, /**< 有功组合电能-普通精度 */
    { FORM_HEX, DT_DOUBLE_LONG, unit_kvarh, -2, F_I32_KVARH_N2 }, /**< 无功组合电能-普通精度 */
    { FORM_HEX, DT_DOUBLE_LONG, unit_kVAh, -2, F_I32_KVAH_N2 }, /**< 视在组合电能-普通精度 */
    { FORM_HEX, DT_DOUBLE_LONG, unit_kWh, -4, F_I32_KWH_N4 }, /**< 有功组合电能-高精度 */
    { FORM_HEX, DT_DOUBLE_LONG, unit_kvarh, -4, F_I32_KVARH_N4 }, /**< 无功组合电能-高精度 */
    { FORM_HEX, DT_DOUBLE_LONG, unit_kVAh, -4, F_I32_KVAH_N4 }, /**< 视在组合电能-高精度 */
    { FORM_HEX, DT_DOUBLE_LONG, unit_W, -1, F_I32_W_N1 }, /**< 有功功率 */
    { FORM_HEX, DT_DOUBLE_LONG, unit_var, -1, F_I32_var_N1 }, /**< 无功功率 */
    { FORM_HEX, DT_DOUBLE_LONG, unit_VA, -1, F_I32_VA_N1 }, /**< 视在功率 */
    { FORM_HEX, DT_LONG, unit_undefined, -3, F_I16_COS_N3 }, /**< 功率因素 */
    { FORM_HEX, DT_LONG_UNSIGNED, unit_angle, -1, F_U16_ANGLE_N1 }, /**< 相角 */
    { FORM_HEX, DT_LONG_UNSIGNED, unit_Hz, -2, F_U16_HZ_N2 }, /**< 频率 */
    { FORM_HEX, DT_DOUBLE_LONG_UNSIGNED, unit_Ah, -2, F_U32_Ah_N2 }, /**< 频率 */
    { FORM_HEX, DT_ARRAY, unit_undefined, 0, F_ARRAY_NUDEF }, /**<   */
    { FORM_HEX, DT_OAD, unit_undefined, 0, F_OAD_NUDEF }, /**<   */
    { FORM_HEX, DT_DATETIME_S, unit_undefined, 0, F_DATETIME_S_NUDEF }, /**<   */
};
const uint8 CODE file_format_num = array_count(file_format);

/*******************数据关注表格****************************/
enum notify_index
{   /* 注意 ：最好是 8 个一行， 中间不允许有间断 */
	notify_00, notify_01, notify_02, notify_03, notify_04, notify_05, notify_06, notify_07, /**< 00 -- 07 */
	notify_08, notify_09, notify_10, notify_11, notify_12, notify_13, notify_14, notify_15, /**< 08 -- 15 */
};


const struct notify_index_t CODE notify_tab[] =
{
    { 0x0000, notify_00 }, /**< 第一行不使用 */
    { fs_notify(name_demand)+fs_notify(name_ctrl), notify_01 }, /**<   */
    { fs_notify(name_ctrl)+fs_notify(name_clock), notify_02 }, /**<   */
    { fs_notify(name_display)+fs_notify(name_ctrl), notify_03 }, /**<   */
    { fs_notify(name_instantaneous), notify_04 }, /**<   */
    { fs_notify(name_clock), notify_05 }, /**<   */
    { fs_notify(name_clock)+fs_notify(name_demand)+fs_notify(name_datapro), notify_06 }, /**< 修改时间多模块通知 */
    { fs_notify(name_datapro), notify_07 }, /**< 修改参数通知 */
    { fs_notify(name_energy), notify_08 }, /**< 修改参数通知 */
    { fs_notify(name_comm), notify_09 }, /**< 修改参数通知 */
    { fs_notify(name_rtc）, notify_10 }, /**< 修改参数通知 */
};
const uint8 CODE file_notify_num = array_count(notify_tab);  /**< 此常量名称不能修改 */

const struct file_t CODE item_para_calibration_tab[] =
{
    { 0x2001, 0x0000, 22, 1, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< A相校表参数 */
    { 0x2002, 0x0018, 22, 1, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< B相校表参数 */
    { 0x2003, 0x0030, 22, 1, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< C相校表参数 */
    { 0x2004, 0x0048, 20, 1, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 测量系数 */
    { 0x2005, 0x005E, 32, 1, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 计量硬件参数 */
    { 0x2006, 0x0080, 4, 1, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 脉冲常数 */
    { 0x2007, 0x0086, 18, 1, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 测量规格参数 */
    { 0x2008, 0x009A, 16, 1, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 计量控制参数 */
    { 0x2009, 0x00AC, 8, 1, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 电能脉冲控制参数 */
    { 0x200A, 0x00B6, 20, 1, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 测量控制参数 */
    { 0x200B, 0x00CC, 4, 1, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 频率修正因子 */
    { 0x200C, 0x00D2, 10, 1, attribute(format_00, notify_10, 0, 0, 0, 1) }, /**< 温度补偿 */
    { 0x200D, 0x00DE, 26, 1, attribute(format_00, notify_08, 0, 0, 0, 1) }, /**< MeasurementPeriod3forInstantaneousvalues */
    { 0x2100, 0x00FA, 16, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 表型 */
    { 0x2101, 0x010C, 17, 1, attribute(format_12, notify_07, 0, 1, 0, 1) }, /**< 通讯地址 */
    { 0x2102, 0x011F, 21, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 硬件版本号长度+硬件版本号 */
    { 0x2103, 0x0136, 23, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 写生产信息 */
    { 0x2104, 0x014F, 11, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 写生产模板号 */
    { 0x2105, 0x015C, 17, 1, attribute(format_00, notify_08, 0, 1, 0, 1) }, /**< 计量终端校表参数 */
    { 0x2107, 0x016F, 9, 1, attribute(format_12, notify_00, 0, 1, 0, 1) }, /**< 表号 */
    { 0x210F, 0x017A, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 编程员ID */
    { 0x2131, 0x0180, 1, 1, attribute(format_16, notify_00, 0, 1, 0, 1) }, /**< 表计总清次数(2) */
    { 0x2132, 0x0183, 4, 2, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 复位标志sign(2)+cnt(2) */
    { 0x2134, 0x018D, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 身份认证时效 */
    { 0x2140, 0x0191, 1, 1, attribute(format_16, notify_01, 0, 1, 0, 1) }, /**< 最大需量周期 */
    { 0x2141, 0x0194, 1, 1, attribute(format_16, notify_01, 0, 1, 0, 1) }, /**< 滑差时间 */
    { 0x2142, 0x0197, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 校表脉冲宽度 */
    { 0x2143, 0x019B, 1, 1, attribute(format_16, notify_00, 0, 1, 0, 1) }, /**< 密钥总条数 */
    { 0x2144, 0x019E, 2, 1, attribute(format_16, notify_03, 0, 1, 0, 1) }, /**< 按键显示退出时间 */
    { 0x2145, 0x01A2, 2, 1, attribute(format_16, notify_03, 0, 1, 0, 1) }, /**< 自动轮显每屏显示时间 */
    { 0x2146, 0x01A6, 4, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 电流互感器变比 */
    { 0x2147, 0x01AC, 4, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 电压互感器变比 */
    { 0x2149, 0x01B2, 1, 1, attribute(format_16, notify_03, 0, 1, 0, 1) }, /**< 按键循环显示屏数 */
    { 0x2150, 0x01B5, 33, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 资产管理编码 */
    { 0x2151, 0x01D8, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 额定电压 */
    { 0x2152, 0x01E1, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 额定电流 */
    { 0x2153, 0x01EA, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 最大电流 */
    { 0x2154, 0x01F3, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 有功准确度等级 */
    { 0x2155, 0x01FA, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 无功准确度等级 */
    { 0x2156, 0x0201, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 有功脉冲常数-通信和显示用 */
    { 0x2157, 0x0207, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 无功脉冲常数-通信和显示用 */
    { 0x2158, 0x020D, 33, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电表型号 */
    { 0x2159, 0x0230, 11, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 生产日期645 */
    { 0x215B, 0x023D, 17, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 协议版本号 */
    { 0x215C, 0x0250, 6, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 额定电流 */
    { 0x215D, 0x0258, 6, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 最大电流 */
    { 0x215F, 0x0260, 7, 1, attribute(format_12, notify_00, 0, 1, 0, 1) }, /**< 客户编号 */
    { 0x2160, 0x0269, 4, 3, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表位置信息经度纬度高度 */
    { 0x2165, 0x0277, 2, 1, attribute(format_13, notify_08, 0, 1, 0, 1) }, /**< 有功组合方式特征字 */
    { 0x2166, 0x027B, 2, 1, attribute(format_13, notify_08, 0, 1, 0, 1) }, /**< 无功组合特征字1.第一个字节表示长度固定为8 */
    { 0x2167, 0x027F, 2, 1, attribute(format_13, notify_08, 0, 1, 0, 1) }, /**< 无功组合特征字2.第一个字节表示长度固定为8 */
    { 0x2168, 0x0283, 4, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 背光报警控制字													 */
    { 0x2169, 0x0289, 4, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 继电器报警控制字 */
    { 0x2170, 0x028F, 1, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 调制型红外光口通信速率特征字 */
    { 0x2176, 0x0296, 1, 1, attribute(format_00, notify_05, 0, 1, 0, 1) }, /**< 周休日特征字 */
    { 0x2177, 0x0299, 1, 1, attribute(format_00, notify_05, 0, 1, 0, 1) }, /**< 周休日采用的日时段表号 */
    { 0x2178, 0x029C, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 负荷记录模式字 */
    { 0x2179, 0x029F, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 定时冻结数据模式字 */
    { 0x217A, 0x02A2, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 瞬时冻结数据模式字 */
    { 0x217B, 0x02A5, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 约定冻结数据模式字 */
    { 0x217C, 0x02A8, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 整点冻结数据模式字 */
    { 0x217D, 0x02AB, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 日冻结数据模式字 */
    { 0x217E, 0x02AE, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 负荷记录起始时间 */
    { 0x2180, 0x02B5, 2, 6, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第1~6通道负荷记录间隔时间 */
    { 0x2190, 0x02C3, 2, 3, attribute(format_00, notify_07, 0, 1, 0, 1) }, /**< 每月第1~3结算日 */
    { 0x21A0, 0x02CB, 4, 10, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 通讯第1~10级密码 */
    { 0x21B0, 0x02F5, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 正向有功功率上限值 */
    { 0x21B1, 0x02FB, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 反向有功功率上限值 */
    { 0x21C0, 0x0301, 2, 4, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电压考核上限、电压考核下限、电压合格上限、电压合格下限 */
    { 0x21D0, 0x030B, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电表运行特征字 */
    { 0x21D1, 0x030E, 8, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 主动上报模式字 */
    { 0x21D2, 0x0318, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 整点冻结起始时间 */
    { 0x21D3, 0x0321, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 整点冻结时间间隔 */
    { 0x21D4, 0x0324, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 日冻结时间 */
    { 0x21D5, 0x0328, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 定时冻结时间 */
    { 0x21D6, 0x032E, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 跳闸延时时间-告警延时 */
    { 0x21D7, 0x0331, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 继电器拉闸控制电流门限值-继电器拉闸电流门限值 */
    { 0x21D8, 0x0337, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 超拉闸控制电流门限保护延时时间-超电流门限保护延时时间 */
    { 0x21D9, 0x033B, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 红外认证时效 */
    { 0x21DA, 0x033E, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 主动上报状态字自动复位延时时间 */
    { 0x21DB, 0x0341, 33, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 软件备案号 */
    { 0x21DC, 0x0364, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 身份认证时效 */
    { 0x21DD, 0x0368, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 限电时间 */
    { 0x21DE, 0x036C, 33, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 认证密码 */
    { 0x21DF, 0x038F, 3, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 广播校时日期-年-月-日 */
    { 0x21E0, 0x0394, 4, 2, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 报警金额限值1~2 */
    { 0x21F0, 0x039E, 4, 3, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 透支金额限值、囤积金额限值、合闸允许金额限值 */
    { 0x2200, 0x03AC, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< LCD参数上电全显时间 */
    { 0x2201, 0x03AF, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< LCD参数按键背光点亮时间 */
    { 0x2202, 0x03B3, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< LCD参数显示查看背光点亮时间 */
    { 0x2203, 0x03B7, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< LCD参数无电按键屏幕驻留最大时间 */
    { 0x2204, 0x03BB, 1, 1, attribute(format_00, notify_03, 0, 1, 0, 1) }, /**< LCD参数显示电能小数位数 */
    { 0x2205, 0x03BE, 1, 1, attribute(format_00, notify_03, 0, 1, 0, 1) }, /**< LCD参数显示功率（最大需量）小数位数 */
    { 0x2206, 0x03C1, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< LCD参数液晶①②字样意义 */
    { 0x2210, 0x03C4, 3, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 期间需量冻结周期 */
    { 0x2211, 0x03C9, 3, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 计量元件数 */
    { 0x2212, 0x03CE, 33, 3, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 厂家软件版本号(ASCII码)												 */
    { 0x2215, 0x0433, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 协议版本信息 */
    { 0x2220, 0x0437, 4, 2, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 报警电量限值1~2 */
    { 0x2230, 0x0441, 4, 3, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 囤积电量限值、透支电量限值、合闸允许电量限值 */
    { 0x2271, 0x044F, 2, 1, attribute(format_00, notify_09, 0, 1, 0, 1) }, /**< 红外-波特率，兼容645参数设置 */
    { 0x2272, 0x0453, 2, 1, attribute(format_00, notify_09, 0, 1, 0, 1) }, /**< RS485-波特率 */
    { 0x2273, 0x0457, 2, 1, attribute(format_00, notify_09, 0, 1, 0, 1) }, /**< 载波-波特率 */
    { 0x2274, 0x045B, 19, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 载波-版本信息 */
    { 0x2300, 0x0470, 199, 1, attribute(format_00, notify_03, 0, 1, 0, 0) }, /**< 自动循环显示对象FSID列表1+99*2 */
    { 0x2301, 0x0537, 199, 1, attribute(format_00, notify_03, 0, 1, 0, 0) }, /**< 按键显示对象FSID列表1+99*2 */
    { 0x2302, 0x05FE, 4, 1, attribute(format_00, notify_03, 0, 1, 0, 1) }, /**< 查询显示前2字节是显示fs_id后2字节是显示持续时间 */
    { 0x2303, 0x0604, 2, 1, attribute(format_00, notify_03, 0, 1, 0, 1) }, /**< 查询全屏显示显示持续时间 */
    { 0x24c0, 0x0608, 33, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-源文件 */
    { 0x24c1, 0x062B, 33, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-目标文件 */
    { 0x24c2, 0x064E, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-文件大小 */
    { 0x24c3, 0x0654, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-文件属性 */
    { 0x24c4, 0x0658, 17, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-文件版本 */
    { 0x24c5, 0x066B, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-命令结果 */
    { 0x24c6, 0x066E, 1027, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-传输块状态字3+512*1024/64/8 */
    { 0x24c7, 0x0A73, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-激活时间 */
    { 0x24c8, 0x0A7C, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-状态 */
    { 0x24c9, 0x0A7F, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-传输块大小 */
    { 0x24ca, 0x0A83, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-文件类别 */
    { 0x24cb, 0x0A87, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-接收的文件包长度 */
    { 0x24cd, 0x0A8D, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 文件信息-crc16 */
    { 0x24d2, 0x0A91, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 安全模式参数使能0-disable1-enable */
    { 0x24d3, 0x0A94, 401, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 显式安全模式参数缓存 */
    { 0x24e0, 0x0C27, 33, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 设备描述符32bytes */
    { 0x24e1, 0x0C4A, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 厂商代码 */
    { 0x24e2, 0x0C51, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 软件版本号 */
    { 0x24e3, 0x0C58, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 软件版本日期 */
    { 0x24e4, 0x0C61, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 硬件版本号 */
    { 0x24e5, 0x0C68, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 硬件版本日期 */
    { 0x24e6, 0x0C71, 9, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 厂家扩展信息 */
    { 0x24e7, 0x0C7C, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 生产日期 */
    { 0x24e8, 0x0C85, 7, 3, attribute(format_00, notify_00, 0, 0, 0, 0) }, /**< 子设备列表1+2*3 */
    { 0x24e9, 0x0C8C, 49, 3, attribute(format_00, notify_00, 0, 0, 0, 0) }, /**< 支持规约列表1+16*3 */
    { 0x24ea, 0x0CBD, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 允许跟随上报 */
    { 0x24eb, 0x0CC0, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 允许主动上报 */
    { 0x24ec, 0x0CC3, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 允许与主站通话 */
    { 0x24ed, 0x0CC6, 13, 3, attribute(format_00, notify_01, 0, 0, 0, 0) }, /**< 上报通道1+4*3 */
    { 0x2503, 0x0CD3, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 时钟电池工作时间 */
    { 0x2517, 0x0CD9, 2, 1, attribute(F_U16_PER_N2, notify_00, 0, 1, 0, 1) }, /**< 电压不平衡率 */
    { 0x2518, 0x0CDD, 2, 1, attribute(F_U16_PER_N2, notify_00, 0, 1, 0, 1) }, /**< 电流不平衡率 */
    { 0x2519, 0x0CE1, 2, 1, attribute(F_U16_PER_N2, notify_00, 0, 1, 0, 1) }, /**< 负载率 */
    { 0x251A, 0x0CE5, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 复位次数 */
    { 0x251B, 0x0CEB, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 非法插卡总次数 */
    { 0x251C, 0x0CF1, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 退费金额 */
    { 0x2520, 0x0CF7, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 开户状态 */
    { 0x2521, 0x0CFA, 8, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 开户卡序列号 */
    { 0x2522, 0x0D04, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 跟随上报状态字 */
    { 0x2523, 0x0D0B, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 跟随上报模式字 */
    { 0x2524, 0x0D12, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 红外认证时效门限 */
    { 0xFFFF, 0x0D18, 300, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 预留300个字节，填加新的ID从这里分配 */
};

const struct file_t CODE item_para_power_off_tab[] =
{
    { 0x2800, 0x1C8C, 276, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 掉电时需要保存的事件状态 */
    { 0x2801, 0x1DA2, 188, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 掉电时累积发生时间 */
    { 0x2802, 0x1E60, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 掉电备份时间 */
    { 0x2803, 0x1E69, 8, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 掉电备份ABC相安时数 */
    { 0x2804, 0x1E73, 8, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 掉电备份ABC相安时数 */
    { 0x2805, 0x1E7D, 8, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 掉电备份ABC相安时数 */
    { 0x2807, 0x1E87, 8, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 当前钱包(剩余电量\剩余金额 */
    { 0xFFFF, 0x1E91, 500, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 预留500个字节，填加新的ID从这里分配 */
};

const struct file_t CODE item_para_tab[] =
{
    { 0x2A01, 0x2087, 8, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**<   */
    { 0x2A02, 0x2091, 12, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**<   */
    { 0x2A03, 0x209F, 8, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**<   */
    { 0x2A04, 0x20A9, 1, 2, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 本地拉闸命令 */
    { 0x2A11, 0x20AD, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 主副套时区表标志 */
    { 0x2A12, 0x20B0, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 主副套时段表标志 */
    { 0x2A13, 0x20B3, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 主副套阶梯表标志 */
    { 0x2A14, 0x20B6, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 主副套费率电价表标志 */
    { 0x2A15, 0x20B9, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前运行年/月阶梯标志 */
    { 0x2A16, 0x20BC, 1, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 上一次远程告警命令2A-触发告警2B-解除报警 */
    { 0x2A17, 0x20BF, 1, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 上一次远程控制命令 */
    { 0x2A18, 0x20C2, 1, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 上一次远程保电命令 */
    { 0x2A19, 0x20C5, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 上一次本地拉合闸命令 */
    { 0x2A1A, 0x20C8, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< last_time上一次月结算时间 */
    { 0x2A1B, 0x20CF, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< last_time上一次日冻结时间 */
    { 0x2A1C, 0x20D6, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< last_time上一次整点冻结时间 */
    { 0x2A1D, 0x20DF, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< last_time上一次定时冻结时间 */
    { 0x2A1E, 0x20E8, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< last_time上一次年结算时间 */
    { 0x2B00, 0x20F1, 7, 1, attribute(F_DATETIME_S_NUDEF, notify_05, 0, 1, 0, 1) }, /**< 修改前的时间（hex格式）秒，分，时，日，月，年（年为2个字节） */
    { 0x2B01, 0x20FA, 7, 1, attribute(F_DATETIME_S_NUDEF, notify_05, 0, 1, 0, 1) }, /**< 修改后的时间（hex格式）秒，分，时，日，月，年（年为2个字节） */
    { 0x2FF1, 0x2103, 52, 1, attribute(format_00, notify_04, 0, 1, 0, 1) }, /**< 自校表 */
    { 0x2FF2, 0x2139, 4, 1, attribute(format_00, notify_10, 0, 1, 0, 1) }, /**< 频率修正PPM */
    { 0x3010, 0x213F, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 3010升级模式 */
    { 0x3015, 0x2142, 40, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 历史电能显示 */
    { 0x3016, 0x216C, 16, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 历史事件显示 */
    { 0x3017, 0x217E, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 校表 */
    { 0x3018, 0x2187, 0, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 校表初始化 */
    { 0xFFFF, 0x2189, 1000, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 预留1000个字节，填加新的ID从这里分配 */
};

const struct file_t CODE item_tariff_tab[] =
{
    { 0x3200, 0x2A5F, 1, 4, attribute(format_00, notify_05, 0, 1, 0, 0) }, /**< 时区时段参数 */
    { 0x3204, 0x2A63, 1, 1, attribute(format_00, notify_05, 0, 1, 0, 1) }, /**< 公共假日数n≤50 */
    { 0x3205, 0x2A66, 1, 2, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 谐波分析次数、阶梯数 */
    { 0x3210, 0x2A6A, 5, 1, attribute(format_00, notify_05, 0, 1, 0, 1) }, /**< 两套时区表切换时间 */
    { 0x3211, 0x2A71, 5, 1, attribute(format_00, notify_05, 0, 1, 0, 1) }, /**< 两套日时段表切换时间,年- */
    { 0x3212, 0x2A78, 5, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 两套分时费率切换时间 */
    { 0x3213, 0x2A7F, 5, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 两套阶梯电价切换时间 */
    { 0x3220, 0x2A86, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第一套时区表数据 */
    { 0x3230, 0x2AB2, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第二套时区表数据 */
    { 0x3240, 0x2ADE, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第一套第1日时段表数据 */
    { 0x3241, 0x2B0A, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第一套第2日时段表数据 */
    { 0x3242, 0x2B36, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第一套第3日时段表数据 */
    { 0x3243, 0x2B62, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第一套第4日时段表数据 */
    { 0x3244, 0x2B8E, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第一套第5日时段表数据 */
    { 0x3245, 0x2BBA, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第一套第6日时段表数据 */
    { 0x3246, 0x2BE6, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第一套第7日时段表数据 */
    { 0x3247, 0x2C12, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第一套第8日时段表数据 */
    { 0x3250, 0x2C3E, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第二套第1日时段表数据 */
    { 0x3251, 0x2C6A, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第二套第2日时段表数据 */
    { 0x3252, 0x2C96, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第二套第3日时段表数据 */
    { 0x3253, 0x2CC2, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第二套第4日时段表数据 */
    { 0x3254, 0x2CEE, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第二套第5日时段表数据 */
    { 0x3255, 0x2D1A, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第二套第6日时段表数据 */
    { 0x3256, 0x2D46, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第二套第7日时段表数据 */
    { 0x3257, 0x2D72, 42, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 第二套第8日时段表数据 */
    { 0x3300, 0x2D9E, 5, 50, attribute(format_00, notify_05, 0, 1, 0, 1) }, /**< 第1~50公假日,年-月-日-周-日时段表号 */
    { 0xFFFF, 0x2E9A, 1000, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 预留1000个字节，填加新的ID从这里分配 */
};

const struct file_t CODE item_para2_tab[] =
{
    { 0x4000, 0x3284, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表正向有功需量超限事件     */
    { 0x4001, 0x331D, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表反向有功需量超限事件 */
    { 0x4002, 0x33B6, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表功率因数超下限事件 */
    { 0x4003, 0x344F, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表全失压事件 */
    { 0x4004, 0x34E8, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表辅助电源掉电事件 */
    { 0x4005, 0x3581, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表电压逆相序事件 */
    { 0x4006, 0x361A, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表电流逆相序事件 */
    { 0x4007, 0x36B3, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表掉电事件 */
    { 0x4008, 0x374C, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表编程事件 */
    { 0x4009, 0x37E5, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表清零事件 */
    { 0x400A, 0x387E, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表需量清零事件 */
    { 0x400B, 0x3917, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表事件清零事件 */
    { 0x400C, 0x39B0, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表校时事件 */
    { 0x400D, 0x3A49, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表时段表编程事件 */
    { 0x400E, 0x3AE2, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表时区表编程事件 */
    { 0x400F, 0x3B7B, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表周休日编程事件 */
    { 0x4010, 0x3C14, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表结算日编程事件 */
    { 0x4011, 0x3CAD, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表开盖事件 */
    { 0x4012, 0x3D46, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表开端钮盒事件 */
    { 0x4013, 0x3DDF, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表电压不平衡事件 */
    { 0x4014, 0x3E78, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表电流不平衡事件 */
    { 0x4015, 0x3F11, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表跳闸事件 */
    { 0x4016, 0x3FAA, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表合闸事件 */
    { 0x4017, 0x4043, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表节假日编程事件 */
    { 0x4018, 0x40DC, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表有功组合方式编程事件 */
    { 0x4019, 0x4175, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表无功组合方式编程事件 */
    { 0x401A, 0x420E, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表费率参数表编程事件 */
    { 0x401B, 0x42A7, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表阶梯表编程事件 */
    { 0x401C, 0x4340, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表密钥更新事件 */
    { 0x401D, 0x43D9, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表异常插卡事件 */
    { 0x401E, 0x4472, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表购电记录 */
    { 0x401F, 0x450B, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表退费记录 */
    { 0x4020, 0x45A4, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表恒定磁场干扰事件 */
    { 0x4021, 0x463D, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表负荷开关误动作事件 */
    { 0x4022, 0x46D6, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表电源异常事件 */
    { 0x4023, 0x476F, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表电流严重不平衡事件 */
    { 0x4024, 0x4808, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表时钟故障事件 */
    { 0x4025, 0x48A1, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表计量芯片故障事件 */
    { 0x4026, 0x493A, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 通信模块变更事件 */
    { 0x4200, 0x49D3, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表正向有功需量超限事件 */
    { 0x4201, 0x49D6, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表反向有功需量超限事件 */
    { 0x4202, 0x49D9, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表功率因数超下限事件 */
    { 0x4203, 0x49DC, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表全失压事件 */
    { 0x4204, 0x49DF, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表辅助电源掉电事件 */
    { 0x4205, 0x49E2, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表电压逆相序事件 */
    { 0x4206, 0x49E5, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表电流逆相序事件 */
    { 0x4207, 0x49E8, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表掉电事件 */
    { 0x4208, 0x49EB, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表编程事件 */
    { 0x4209, 0x49EE, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表清零事件 */
    { 0x420A, 0x49F1, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表需量清零事件 */
    { 0x420B, 0x49F4, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表事件清零事件 */
    { 0x420C, 0x49F7, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表校时事件 */
    { 0x420D, 0x49FA, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表时段表编程事件 */
    { 0x420E, 0x49FD, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表时区表编程事件 */
    { 0x420F, 0x4A00, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表周休日编程事件 */
    { 0x4210, 0x4A03, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表结算日编程事件 */
    { 0x4211, 0x4A06, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表开盖事件 */
    { 0x4212, 0x4A09, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表开端钮盒事件 */
    { 0x4213, 0x4A0C, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表电压不平衡事件 */
    { 0x4214, 0x4A0F, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表电流不平衡事件 */
    { 0x4215, 0x4A12, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表跳闸事件 */
    { 0x4216, 0x4A15, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表合闸事件 */
    { 0x4217, 0x4A18, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表节假日编程事件 */
    { 0x4218, 0x4A1B, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表有功组合方式编程事件 */
    { 0x4219, 0x4A1E, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表无功组合方式编程事件 */
    { 0x421A, 0x4A21, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表费率参数表编程事件 */
    { 0x421B, 0x4A24, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表阶梯表编程事件 */
    { 0x421C, 0x4A27, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表密钥更新事件 */
    { 0x421D, 0x4A2A, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表异常插卡事件 */
    { 0x421E, 0x4A2D, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表购电记录 */
    { 0x421F, 0x4A30, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表退费记录 */
    { 0x4220, 0x4A33, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表恒定磁场干扰事件 */
    { 0x4221, 0x4A36, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表负荷开关误动作事件 */
    { 0x4222, 0x4A39, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表电源异常事件 */
    { 0x4223, 0x4A3C, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表电流严重不平衡事件 */
    { 0x4224, 0x4A3F, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表时钟故障事件 */
    { 0x4225, 0x4A42, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 电能表计量芯片故障事件 */
    { 0x4226, 0x4A45, 1, 1, attribute(F_ENUM, notify_00, 0, 1, 0, 1) }, /**< 通信模块变更事件 */
    { 0x4240, 0x4A48, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表正向有功需量超限事件 */
    { 0x4241, 0x4A4B, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表反向有功需量超限事件 */
    { 0x4242, 0x4A4E, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表功率因数超下限事件 */
    { 0x4243, 0x4A51, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表全失压事件 */
    { 0x4244, 0x4A54, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表辅助电源掉电事件 */
    { 0x4245, 0x4A57, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表电压逆相序事件 */
    { 0x4246, 0x4A5A, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表电流逆相序事件 */
    { 0x4247, 0x4A5D, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表掉电事件 */
    { 0x4248, 0x4A60, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表编程事件 */
    { 0x4249, 0x4A63, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表清零事件 */
    { 0x424A, 0x4A66, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表需量清零事件 */
    { 0x424B, 0x4A69, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表事件清零事件 */
    { 0x424C, 0x4A6C, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表校时事件 */
    { 0x424D, 0x4A6F, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表时段表编程事件 */
    { 0x424E, 0x4A72, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表时区表编程事件 */
    { 0x424F, 0x4A75, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表周休日编程事件 */
    { 0x4250, 0x4A78, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表结算日编程事件 */
    { 0x4251, 0x4A7B, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表开盖事件 */
    { 0x4252, 0x4A7E, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表开端钮盒事件 */
    { 0x4253, 0x4A81, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表电压不平衡事件 */
    { 0x4254, 0x4A84, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表电流不平衡事件 */
    { 0x4255, 0x4A87, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表跳闸事件 */
    { 0x4256, 0x4A8A, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表合闸事件 */
    { 0x4257, 0x4A8D, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表节假日编程事件 */
    { 0x4258, 0x4A90, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表有功组合方式编程事件 */
    { 0x4259, 0x4A93, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表无功组合方式编程事件 */
    { 0x425A, 0x4A96, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表费率参数表编程事件 */
    { 0x425B, 0x4A99, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表阶梯表编程事件 */
    { 0x425C, 0x4A9C, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表密钥更新事件 */
    { 0x425D, 0x4A9F, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表异常插卡事件 */
    { 0x425E, 0x4AA2, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表购电记录 */
    { 0x425F, 0x4AA5, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表退费记录 */
    { 0x4260, 0x4AA8, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表恒定磁场干扰事件 */
    { 0x4261, 0x4AAB, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表负荷开关误动作事件 */
    { 0x4262, 0x4AAE, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表电源异常事件 */
    { 0x4263, 0x4AB1, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表电流严重不平衡事件 */
    { 0x4264, 0x4AB4, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表时钟故障事件 */
    { 0x4265, 0x4AB7, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 电能表计量芯片故障事件 */
    { 0x4266, 0x4ABA, 1, 1, attribute(F_BOOL, notify_00, 0, 1, 0, 1) }, /**< 通信模块变更事件 */
    { 0x4300, 0x4ABD, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表正向有功需量超限事件 */
    { 0x4301, 0x4AC2, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表反向有功需量超限事件 */
    { 0x4302, 0x4AC7, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表功率因数超下限事件 */
    { 0x4303, 0x4ACC, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表全失压事件 */
    { 0x4304, 0x4AD1, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表辅助电源掉电事件 */
    { 0x4305, 0x4AD6, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表电压逆相序事件 */
    { 0x4306, 0x4ADB, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表电流逆相序事件 */
    { 0x4307, 0x4AE0, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表掉电事件 */
    { 0x4308, 0x4AE5, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表编程事件 */
    { 0x4309, 0x4AEA, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表清零事件 */
    { 0x430A, 0x4AEF, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表需量清零事件 */
    { 0x430B, 0x4AF4, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表事件清零事件 */
    { 0x430C, 0x4AF9, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表校时事件 */
    { 0x430D, 0x4AFE, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表时段表编程事件 */
    { 0x430E, 0x4B03, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表时区表编程事件 */
    { 0x430F, 0x4B08, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表周休日编程事件 */
    { 0x4310, 0x4B0D, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表结算日编程事件 */
    { 0x4311, 0x4B12, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表开盖事件 */
    { 0x4312, 0x4B17, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表开端钮盒事件 */
    { 0x4313, 0x4B1C, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表电压不平衡事件 */
    { 0x4314, 0x4B21, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表电流不平衡事件 */
    { 0x4315, 0x4B26, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表跳闸事件 */
    { 0x4316, 0x4B2B, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表合闸事件 */
    { 0x4317, 0x4B30, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表节假日编程事件 */
    { 0x4318, 0x4B35, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表有功组合方式编程事件 */
    { 0x4319, 0x4B3A, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表无功组合方式编程事件 */
    { 0x431A, 0x4B3F, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表费率参数表编程事件 */
    { 0x431B, 0x4B44, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表阶梯表编程事件 */
    { 0x431C, 0x4B49, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表密钥更新事件 */
    { 0x431D, 0x4B4E, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表异常插卡事件 */
    { 0x431E, 0x4B53, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表购电记录 */
    { 0x431F, 0x4B58, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表退费记录 */
    { 0x4320, 0x4B5D, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表恒定磁场干扰事件 */
    { 0x4321, 0x4B62, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表负荷开关误动作事件 */
    { 0x4322, 0x4B67, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表电源异常事件 */
    { 0x4323, 0x4B6C, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表电流严重不平衡事件 */
    { 0x4324, 0x4B71, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表时钟故障事件 */
    { 0x4325, 0x4B76, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表计量芯片故障事件 */
    { 0x4326, 0x4B7B, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 通信模块变更事件 */
    { 0x4340, 0x4B80, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表正向有功需量超限事件 */
    { 0x4341, 0x4B86, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表反向有功需量超限事件 */
    { 0x4342, 0x4B8C, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表功率因数超下限事件 */
    { 0x4343, 0x4B92, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表全失压事件 */
    { 0x4344, 0x4B98, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表辅助电源掉电事件 */
    { 0x4345, 0x4B9E, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表电压逆相序事件 */
    { 0x4346, 0x4BA4, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表电流逆相序事件 */
    { 0x4347, 0x4BAA, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表掉电事件 */
    { 0x4348, 0x4BB0, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表编程事件 */
    { 0x4349, 0x4BB6, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表清零事件 */
    { 0x434A, 0x4BBC, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表需量清零事件 */
    { 0x434B, 0x4BC2, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表事件清零事件 */
    { 0x434C, 0x4BC8, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表校时事件 */
    { 0x434D, 0x4BCE, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表时段表编程事件 */
    { 0x434E, 0x4BD4, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表时区表编程事件 */
    { 0x434F, 0x4BDA, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表周休日编程事件 */
    { 0x4350, 0x4BE0, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表结算日编程事件 */
    { 0x4351, 0x4BE6, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表开盖事件 */
    { 0x4352, 0x4BEC, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表开端钮盒事件 */
    { 0x4353, 0x4BF2, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表电压不平衡事件 */
    { 0x4354, 0x4BF8, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表电流不平衡事件 */
    { 0x4355, 0x4BFE, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表跳闸事件 */
    { 0x4356, 0x4C04, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表合闸事件 */
    { 0x4357, 0x4C0A, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表节假日编程事件 */
    { 0x4358, 0x4C10, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表有功组合方式编程事件 */
    { 0x4359, 0x4C16, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表无功组合方式编程事件 */
    { 0x435A, 0x4C1C, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表费率参数表编程事件 */
    { 0x435B, 0x4C22, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表阶梯表编程事件 */
    { 0x435C, 0x4C28, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表密钥更新事件 */
    { 0x435D, 0x4C2E, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表异常插卡事件 */
    { 0x435E, 0x4C34, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表购电记录 */
    { 0x435F, 0x4C3A, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表退费记录 */
    { 0x4360, 0x4C40, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表恒定磁场干扰事件 */
    { 0x4361, 0x4C46, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表负荷开关误动作事件 */
    { 0x4362, 0x4C4C, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表电源异常事件 */
    { 0x4363, 0x4C52, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表电流严重不平衡事件 */
    { 0x4364, 0x4C58, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表时钟故障事件 */
    { 0x4365, 0x4C5E, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表计量芯片故障事件 */
    { 0x4366, 0x4C64, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 通信模块变更事件 */
    { 0x44FF, 0x4C6A, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 非法插卡总次数 */
    { 0x4500, 0x4C70, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表失压事件 */
    { 0x4501, 0x4D09, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表欠压事件 */
    { 0x4502, 0x4DA2, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表过压事件 */
    { 0x4503, 0x4E3B, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表断相事件 */
    { 0x4504, 0x4ED4, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表失流事件 */
    { 0x4505, 0x4F6D, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表过流事件 */
    { 0x4506, 0x5006, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表断流事件 */
    { 0x4507, 0x509F, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表功率反向事件 */
    { 0x4508, 0x5138, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表过载事件 */
    { 0x4509, 0x51D1, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 电能表无功需量超限事件 */
    { 0x4580, 0x526A, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表失压事件 */
    { 0x4581, 0x526D, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表欠压事件 */
    { 0x4582, 0x5270, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表过压事件 */
    { 0x4583, 0x5273, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表断相事件 */
    { 0x4584, 0x5276, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表失流事件 */
    { 0x4585, 0x5279, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表过流事件 */
    { 0x4586, 0x527C, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表断流事件 */
    { 0x4587, 0x527F, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表功率反向事件 */
    { 0x4588, 0x5282, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表过载事件 */
    { 0x4589, 0x5285, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表无功需量超限事件 */
    { 0x4590, 0x5288, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表失压事件 */
    { 0x4591, 0x528B, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表欠压事件 */
    { 0x4592, 0x528E, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表过压事件 */
    { 0x4593, 0x5291, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表断相事件 */
    { 0x4594, 0x5294, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表失流事件 */
    { 0x4595, 0x5297, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表过流事件 */
    { 0x4596, 0x529A, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表断流事件 */
    { 0x4597, 0x529D, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表功率反向事件 */
    { 0x4598, 0x52A0, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表过载事件 */
    { 0x4599, 0x52A3, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 电能表无功需量超限事件 */
    { 0x4702, 0x52A6, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 失压统计-最近一次失压发生时间 */
    { 0x4703, 0x52AF, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 失压统计-最近一次失压结束时间 */
    { 0x4717, 0x52B8, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表功率反向事件 */
    { 0x4718, 0x52BE, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表过载事件 */
    { 0x4719, 0x52C4, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表无功需量超限事件 */
    { 0x4720, 0x52CA, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表失压事件 */
    { 0x4721, 0x52D0, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表欠压事件 */
    { 0x4722, 0x52D6, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表过压事件 */
    { 0x4723, 0x52DC, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表断相事件 */
    { 0x4724, 0x52E2, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表失流事件 */
    { 0x4725, 0x52E8, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表过流事件 */
    { 0x4726, 0x52EE, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表断流事件 */
    { 0x4727, 0x52F4, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表功率反向事件 */
    { 0x4728, 0x52FA, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表过载事件 */
    { 0x4729, 0x5300, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表无功需量超限事件 */
    { 0x4730, 0x5306, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表失压事件 */
    { 0x4731, 0x530C, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表欠压事件 */
    { 0x4732, 0x5312, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表过压事件 */
    { 0x4733, 0x5318, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表断相事件 */
    { 0x4734, 0x531E, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表失流事件 */
    { 0x4735, 0x5324, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表过流事件 */
    { 0x4736, 0x532A, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表断流事件 */
    { 0x4737, 0x5330, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表功率反向事件 */
    { 0x4738, 0x5336, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表过载事件 */
    { 0x4739, 0x533C, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表无功需量超限事件 */
    { 0x4740, 0x5342, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表失压事件 */
    { 0x4741, 0x5348, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表欠压事件 */
    { 0x4742, 0x534E, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表过压事件 */
    { 0x4743, 0x5354, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表断相事件 */
    { 0x4744, 0x535A, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表失流事件 */
    { 0x4745, 0x5360, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表过流事件 */
    { 0x4746, 0x5366, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表断流事件 */
    { 0x4747, 0x536C, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表功率反向事件 */
    { 0x4748, 0x5372, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表过载事件 */
    { 0x4749, 0x5378, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 电能表无功需量超限事件 */
    { 0x4757, 0x537E, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表功率反向事件 */
    { 0x4758, 0x5383, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表过载事件 */
    { 0x4759, 0x5388, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表无功需量超限事件 */
    { 0x4760, 0x538D, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表失压事件 */
    { 0x4761, 0x5392, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表欠压事件 */
    { 0x4762, 0x5397, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表过压事件 */
    { 0x4763, 0x539C, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表断相事件 */
    { 0x4764, 0x53A1, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表失流事件 */
    { 0x4765, 0x53A6, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表过流事件 */
    { 0x4766, 0x53AB, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表断流事件 */
    { 0x4767, 0x53B0, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表功率反向事件 */
    { 0x4768, 0x53B5, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表过载事件 */
    { 0x4769, 0x53BA, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表无功需量超限事件 */
    { 0x4770, 0x53BF, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表失压事件 */
    { 0x4771, 0x53C4, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表欠压事件 */
    { 0x4772, 0x53C9, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表过压事件 */
    { 0x4773, 0x53CE, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表断相事件 */
    { 0x4774, 0x53D3, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表失流事件 */
    { 0x4775, 0x53D8, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表过流事件 */
    { 0x4776, 0x53DD, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表断流事件 */
    { 0x4777, 0x53E2, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表功率反向事件 */
    { 0x4778, 0x53E7, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表过载事件 */
    { 0x4779, 0x53EC, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表无功需量超限事件 */
    { 0x4780, 0x53F1, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表失压事件 */
    { 0x4781, 0x53F6, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表欠压事件 */
    { 0x4782, 0x53FB, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表过压事件 */
    { 0x4783, 0x5400, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表断相事件 */
    { 0x4784, 0x5405, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表失流事件 */
    { 0x4785, 0x540A, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表过流事件 */
    { 0x4786, 0x540F, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表断流事件 */
    { 0x4787, 0x5414, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表功率反向事件 */
    { 0x4788, 0x5419, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表过载事件 */
    { 0x4789, 0x541E, 3, 3, attribute(format_17, notify_00, 0, 0, 0, 1) }, /**< 电能表无功需量超限事件 */
    { 0x4900, 0x5423, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 瞬时冻结 */
    { 0x4901, 0x543D, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 秒冻结 */
    { 0x4902, 0x5457, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 分冻结 */
    { 0x4903, 0x5471, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 小时冻结 */
    { 0x4904, 0x548B, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 日冻结 */
    { 0x4905, 0x54A5, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 结算日冻结 */
    { 0x4906, 0x54BF, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 月冻结 */
    { 0x4907, 0x54D9, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 年冻结 */
    { 0x4908, 0x54F3, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 时区表切换冻结 */
    { 0x4909, 0x550D, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 日时段表切换冻结 */
    { 0x490A, 0x5527, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 费率电价切换冻结 */
    { 0x490B, 0x5541, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 阶梯切换冻结 */
    { 0x490C, 0x555B, 24, 8, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 阶梯结算冻结 */
    { 0x4910, 0x5575, 71, 20, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 瞬时冻结 */
    { 0x4912, 0x55BE, 71, 20, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 分冻结 */
    { 0x4913, 0x5607, 31, 10, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 小时冻结 */
    { 0x4914, 0x5628, 91, 30, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 日冻结 */
    { 0x4915, 0x5685, 61, 20, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 结算日冻结 */
    { 0x4916, 0x56C4, 151, 50, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 月冻结 */
    { 0x4918, 0x575D, 61, 20, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 时区表切换冻结 */
    { 0x4919, 0x579C, 61, 20, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 日时段表切换冻结 */
    { 0x491A, 0x57DB, 61, 20, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 费率电价切换冻结 */
    { 0x491B, 0x581A, 61, 20, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 阶梯切换冻结 */
    { 0x491C, 0x5859, 31, 10, attribute(format_00, notify_07, 0, 0, 0, 1) }, /**< 阶梯结算冻结 */
    { 0x4920, 0x587A, 41, 20, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 瞬时冻结 */
    { 0x4922, 0x58A5, 41, 20, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 分冻结 */
    { 0x4923, 0x58D0, 21, 10, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 小时冻结 */
    { 0x4924, 0x58E7, 61, 30, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 日冻结 */
    { 0x4925, 0x5926, 41, 20, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 结算日冻结 */
    { 0x4926, 0x5951, 101, 50, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 月冻结 */
    { 0x4928, 0x59B8, 41, 20, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 时区表切换冻结 */
    { 0x4929, 0x59E3, 41, 20, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 日时段表切换冻结 */
    { 0x492A, 0x5A0E, 41, 20, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 费率电价切换冻结 */
    { 0x492B, 0x5A39, 41, 20, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 阶梯切换冻结 */
    { 0x492C, 0x5A64, 21, 10, attribute(format_00, notify_00, 0, 0, 0, 1) }, /**< 阶梯结算冻结 */
    { 0x4930, 0x5A7B, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 瞬时冻结 */
    { 0x4931, 0x5A81, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 秒冻结 */
    { 0x4932, 0x5A87, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 分冻结 */
    { 0x4933, 0x5A8D, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 小时冻结 */
    { 0x4934, 0x5A93, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 日冻结 */
    { 0x4935, 0x5A99, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 结算日冻结 */
    { 0x4936, 0x5A9F, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 月冻结 */
    { 0x4937, 0x5AA5, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 年冻结 */
    { 0x4938, 0x5AAB, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 时区表切换冻结 */
    { 0x4939, 0x5AB1, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 日时段表切换冻结 */
    { 0x493A, 0x5AB7, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 费率电价切换冻结 */
    { 0x493B, 0x5ABD, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 阶梯切换冻结 */
    { 0x493C, 0x5AC3, 4, 1, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 阶梯结算冻结 */
    { 0x4940, 0x5AC9, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 瞬时冻结 */
    { 0x4941, 0x5ACD, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 秒冻结 */
    { 0x4942, 0x5AD1, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 分冻结 */
    { 0x4943, 0x5AD5, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 小时冻结 */
    { 0x4944, 0x5AD9, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 日冻结 */
    { 0x4945, 0x5ADD, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 结算日冻结 */
    { 0x4946, 0x5AE1, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 月冻结 */
    { 0x4947, 0x5AE5, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 年冻结 */
    { 0x4948, 0x5AE9, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 时区表切换冻结 */
    { 0x4949, 0x5AED, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 日时段表切换冻结 */
    { 0x494A, 0x5AF1, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 费率电价切换冻结 */
    { 0x494B, 0x5AF5, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 阶梯切换冻结 */
    { 0x494C, 0x5AF9, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 阶梯结算冻结 */
    { 0x4950, 0x5AFD, 4, 8, attribute(format_15, notify_00, 0, 1, 0, 1) }, /**< 分钟冻结序号 */
    { 0x4B00, 0x5B1F, 161, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 事件上报对象使能列表 */
    { 0x4B10, 0x5BC2, 321, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 事件上报OAD列表1 */
    { 0x4B11, 0x5D05, 321, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 事件上报OAD列表2 */
    { 0x4B12, 0x5E48, 321, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 事件上报OAD列表3 */
    { 0x4B13, 0x5F8B, 52, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 编程对象列表arrayOAD2+10*5 */
    { 0x4B14, 0x5FC1, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 超限期间需量最大值double-long-unsigned */
    { 0x4B15, 0x5FC8, 8, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 超限期间需量最大值发生时间date_time_s */
    { 0x4B16, 0x5FD2, 113, 1, attribute(F_ARRAY_NUDEF, notify_00, 0, 1, 0, 1) }, /**< 编程前当前套时段表日时段表1+8*14 */
    { 0x4B17, 0x6045, 113, 1, attribute(F_ARRAY_NUDEF, notify_00, 0, 1, 0, 1) }, /**< 编程前备用套时段表日时段表1+8*14 */
    { 0x4B18, 0x60B8, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 编程节假日对象OAD */
    { 0x4B19, 0x60BF, 10, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 编程前节假日内容公共假日 */
    { 0x4B1A, 0x60CB, 10, 1, attribute(format_14, notify_00, 0, 1, 0, 1) }, /**< 负荷开关误动作状态040A0130160?16001600 */
    { 0x4B1B, 0x60D7, 113, 1, attribute(F_ARRAY_NUDEF, notify_00, 0, 1, 0, 1) }, /**< 编程前当前套时区表1+14*8 */
    { 0x4B1C, 0x614A, 113, 1, attribute(F_ARRAY_NUDEF, notify_00, 0, 1, 0, 1) }, /**< 编程前备用套时区表1+14*8 */
    { 0x4B1D, 0x61BD, 1, 1, attribute(format_16, notify_00, 0, 1, 0, 1) }, /**< 编程前周休日采用的日时段表号 */
    { 0x4B1E, 0x61C0, 19, 1, attribute(F_ARRAY_NUDEF, notify_00, 0, 1, 0, 1) }, /**< 编程前结算日1+6*3 */
    { 0x4B1F, 0x61D5, 2, 1, attribute(format_13, notify_00, 0, 1, 0, 1) }, /**< 编程前有功组合方式特征字len+value */
    { 0x4B20, 0x61D9, 2, 1, attribute(format_13, notify_00, 0, 1, 0, 1) }, /**< 编程前无功组合方式1特征字len+value */
    { 0x4B21, 0x61DD, 2, 1, attribute(format_13, notify_00, 0, 1, 0, 1) }, /**< 编程前无功组合方式2特征字len+value */
    { 0x4B22, 0x61E1, 161, 1, attribute(F_ARRAY_NUDEF, notify_00, 0, 1, 0, 1) }, /**< 编程前当前套费率电价1+32*5 */
    { 0x4B23, 0x6284, 161, 1, attribute(F_ARRAY_NUDEF, notify_00, 0, 1, 0, 1) }, /**< 编程前备用套费率电价1+32*5 */
    { 0x4B24, 0x6327, 104, 1, attribute(format_14, notify_00, 0, 1, 0, 1) }, /**< 编程前当前套阶梯电价1+(2+6*5)+(2+7*5)+4*8 */
    { 0x4B25, 0x6391, 104, 1, attribute(format_14, notify_00, 0, 1, 0, 1) }, /**< 编程前备用套阶梯电价1+(2+6*5)+(2+7*5)+(2+4*8) */
    { 0x4B26, 0x63FB, 5, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 编程时段表对象 */
    { 0x4B30, 0x6402, 7, 14, attribute(format_14, notify_00, 0, 1, 0, 1) }, /**< 编程前当前套时区表1..14 */
    { 0x4B40, 0x6468, 7, 14, attribute(format_14, notify_00, 0, 1, 0, 1) }, /**< 编程前备用套时区表1..14 */
    { 0x4B50, 0x64CE, 113, 8, attribute(F_ARRAY_NUDEF, notify_00, 0, 1, 0, 1) }, /**< 编程前当前套日时段表1..8 */
    { 0x4B60, 0x685A, 113, 8, attribute(F_ARRAY_NUDEF, notify_00, 0, 1, 0, 1) }, /**< 编程前备用套日时段表1..8 */
    { 0x4C00, 0x6BE6, 3, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 最近一次编程日期 */
    { 0x4C01, 0x6BEB, 2, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 最近一次编程时间 */
    { 0x4C10, 0x6BEF, 1, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 明文合闸密码错误次数 */
    { 0x4C11, 0x6BF2, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 明文合闸密码错误起始时间 */
    { 0x4C12, 0x6BF8, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 直接读fs_id通信次数统计 */
    { 0x4C13, 0x6BFE, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 直接写fs_id通信次数统计不要弄成同类项 */
    { 0x4C14, 0x6C04, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 通信成功率统计 */
    { 0x4C20, 0x6C0A, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< A相电能表失压时的安时值 */
    { 0x4C21, 0x6C10, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< B相电能表失压时的安时值 */
    { 0x4C22, 0x6C16, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< C相电能表失压时的安时值 */
    { 0x4C23, 0x6C1C, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< A相电能表欠压时的安时值 */
    { 0x4C24, 0x6C22, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< B相电能表欠压时的安时值 */
    { 0x4C25, 0x6C28, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< C相电能表欠压时的安时值 */
    { 0x4C26, 0x6C2E, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< A相电能表过压时的安时值 */
    { 0x4C27, 0x6C34, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< B相电能表过压时的安时值 */
    { 0x4C28, 0x6C3A, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< C相电能表过压时的安时值 */
    { 0x4C29, 0x6C40, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< A相电能表断相时的安时值 */
    { 0x4C2A, 0x6C46, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< B相电能表断相时的安时值 */
    { 0x4C2B, 0x6C4C, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< C相电能表断相时的安时值 */
    { 0x4C2C, 0x6C52, 22, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 修改时间到历史时间，需要覆盖冻结的信息 */
    { 0x4C2D, 0x6C6A, 1, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 外置继电器开关属性:脉冲式（0），保持式（1） */
    { 0x4C2E, 0x6C6D, 1, 1, attribute(format_00, notify_02, 0, 1, 0, 1) }, /**< 外置继电器脉冲式脉冲宽度，默认40,分辨率10ms  */
    { 0x4C30, 0x6C70, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 事件清零列表  array OMD */
    { 0x4C31, 0x6C79, 8, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 模块对应的通信地址 */
    { 0x4C32, 0x6C83, 17, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 变更前的模块描述符 */
    { 0x4C33, 0x6C96, 17, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 变更后的模块描述符 */
    { 0x4C34, 0x6CA9, 10, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 生产模板号 */
    { 0x4C35, 0x6CB5, 10, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 生产模板号（备用） */
    { 0x4C36, 0x6CC1, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 无功组合模式字1发生次数 */
    { 0x4C37, 0x6CC7, 4, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 无功组合模式字2发生次数 */
    { 0x4C38, 0x6CCD, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 无功组合模式字1发生时间 */
    { 0x4C39, 0x6CD6, 7, 1, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 无功组合模式字2发生时间 */
    { 0xFFFF, 0x6CDF, 2883, 1, attribute(format_00, notify_00, 0, N/A, 0, 1) }, /**< 预留3000个字节，填加新的ID从这里分配 */
};

const struct file_t CODE dlt645_billing_tab[] =
{
    { 0x5000, 0x7824, 6144, 12, attribute(format_00, notify_00, 0, 2, 0, 0) }, /**< DLT645-2007电能量结算转存 */
    { 0x5010, 0x9024, 3200, 10, attribute(format_00, notify_00, 0, 2, 0, 0) }, /**< A相失压 */
    { 0x5011, 0x9CA4, 3200, 10, attribute(format_00, notify_00, 0, 2, 0, 0) }, /**< B相失压 */
    { 0x5012, 0xA924, 3200, 10, attribute(format_00, notify_00, 0, 2, 0, 0) }, /**< C相失压 */
    { 0x5013, 0xB5A4, 800, 10, attribute(format_00, notify_00, 0, 2, 0, 0) }, /**< 电能表掉电事件 */
    { 0x5014, 0xB8C4, 800, 10, attribute(format_00, notify_00, 0, 2, 0, 0) }, /**< 电能表全失压事件 */
    { 0x5015, 0xBBE4, 1300, 10, attribute(format_00, notify_00, 0, 2, 0, 0) }, /**< 电能表开盖事件 */
    { 0x5016, 0xC0F8, 1300, 10, attribute(format_00, notify_00, 0, 2, 0, 0) }, /**< 电能表开端钮盒事件 */
    { 0x5017, 0xC60C, 800, 10, attribute(format_00, notify_00, 0, 2, 0, 0) }, /**< 电能表电源异常事件 */
    { 0x5018, 0xC92C, 1150, 10, attribute(format_00, notify_00, 0, 2, 0, 0) }, /**< 电能表编程事件 */
    { 0xFFFF, 0xCDAA, 1000, 1, attribute(format_00, notify_00, 0, N/A, 0, 1) }, /**< 预留1000个字节，填加新的ID从这里分配 */
};

const struct file_t CODE item_energy_powoff_save_tab[] =
{
    { 0x8000, 0xD546, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础有功电能+ */
    { 0x8010, 0xD552, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础有功电能- */
    { 0x8020, 0xD55E, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础无功电能1 */
    { 0x8030, 0xD56A, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础无功电能2 */
    { 0x8040, 0xD576, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础无功电能3 */
    { 0x8050, 0xD582, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础无功电能4 */
    { 0x8100, 0xD58E, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础有功电能+ */
    { 0x8110, 0xD59A, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础有功电能- */
    { 0x8120, 0xD5A6, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础无功电能1 */
    { 0x8130, 0xD5B2, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础无功电能2 */
    { 0x8140, 0xD5BE, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础无功电能3 */
    { 0x8150, 0xD5CA, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础无功电能4 */
    { 0x8200, 0xD5D6, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础有功电能+ */
    { 0x8210, 0xD5E2, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础有功电能- */
    { 0x8220, 0xD5EE, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础无功电能1 */
    { 0x8230, 0xD5FA, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础无功电能2 */
    { 0x8240, 0xD606, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础无功电能3 */
    { 0x8250, 0xD612, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础无功电能4 */
    { 0x8300, 0xD61E, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总有功电能+ */
    { 0x8310, 0xD62A, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总有功电能- */
    { 0x8320, 0xD636, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总无功电能1 */
    { 0x8330, 0xD642, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总无功电能2 */
    { 0x8340, 0xD64E, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总无功电能3 */
    { 0x8350, 0xD65A, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总无功电能4 */
    { 0x8400, 0xD666, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础月度有功总 */
    { 0x8410, 0xD672, 2, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础年度有功总 */
    { 0xFFFF, 0xD67E, 200, 1, attribute(format_00, notify_00, 0, N/A, 0, 1) }, /**< 预留200个字节，填加新的ID从这里分配 */
};

const struct file_t CODE item_energySave_tab[] =
{
    { 0x8880, 0xD748, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础月度有功总 */
    { 0x8890, 0xD75E, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础年度有功总 */
    { 0x8C80, 0xD774, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础有功电能+ */
    { 0x8C90, 0xD78A, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础有功电能- */
    { 0x8CA0, 0xD7A0, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础无功电能1 */
    { 0x8CB0, 0xD7B6, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础无功电能2 */
    { 0x8CC0, 0xD7CC, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础无功电能3 */
    { 0x8CD0, 0xD7E2, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前A相基础无功电能4 */
    { 0x8D80, 0xD7F8, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础有功电能+ */
    { 0x8D90, 0xD80E, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础有功电能- */
    { 0x8DA0, 0xD824, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础无功电能1 */
    { 0x8DB0, 0xD83A, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础无功电能2 */
    { 0x8DC0, 0xD850, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础无功电能3 */
    { 0x8DD0, 0xD866, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前B相基础无功电能4 */
    { 0x8E80, 0xD87C, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础有功电能+ */
    { 0x8E90, 0xD892, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础有功电能- */
    { 0x8EA0, 0xD8A8, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础无功电能1 */
    { 0x8EB0, 0xD8BE, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础无功电能2 */
    { 0x8EC0, 0xD8D4, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础无功电能3 */
    { 0x8ED0, 0xD8EA, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前C相基础无功电能4 */
    { 0x8F80, 0xD900, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总有功电能+ */
    { 0x8F90, 0xD916, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总有功电能- */
    { 0x8FA0, 0xD92C, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总无功电能1 */
    { 0x8FB0, 0xD942, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总无功电能2 */
    { 0x8FC0, 0xD958, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总无功电能3 */
    { 0x8FD0, 0xD96E, 4, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< 当前基础总无功电能4 */
    { 0xFFFF, 0xD984, 200, 1, attribute(format_00, notify_00, 0, N/A, 0, 1) }, /**< 预留100个字节，填加新的ID从这里分配 */
};

const struct file_t CODE item_demand_tab[] =
{
    { 0xA010, 0xDD54, 4, 5, attribute(format_01, notify_00, 0, 1, 0, 1) }, /**< ActiveMD(+) */
    { 0xA020, 0xDD6A, 4, 5, attribute(format_01, notify_00, 0, 1, 0, 1) }, /**< ActiveMD(-) */
    { 0xA050, 0xDD80, 4, 5, attribute(F_U32_KVAR_N4, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QI) */
    { 0xA060, 0xDD96, 4, 5, attribute(F_U32_KVAR_N4, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QII) */
    { 0xA070, 0xDDAC, 4, 5, attribute(F_U32_KVAR_N4, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QIII) */
    { 0xA080, 0xDDC2, 4, 5, attribute(F_U32_KVAR_N4, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QIV) */
    { 0xA090, 0xDDD8, 4, 5, attribute(format_20, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(+) */
    { 0xA0A0, 0xDDEE, 4, 5, attribute(format_20, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(-) */
    { 0xA500, 0xDE04, 64, 1, attribute(format_03, notify_00, 0, 0, 0, 1) }, /**< 当日电压合格率统计数据 */
    { 0xA501, 0xDE46, 64, 1, attribute(format_03, notify_00, 0, 0, 0, 1) }, /**< 当月电压合格率统计数据 */
    { 0xA600, 0xDE88, 1, 1, attribute(format_03, notify_00, 0, 1, 0, 1) }, /**< 停电低功耗事件执行次数限制标志 */
    { 0xB010, 0xDE8B, 5, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< ActiveMD(+)&occurringtime */
    { 0xB020, 0xDEA6, 5, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< ActiveMD(-)&occurringtime */
    { 0xB050, 0xDEC1, 5, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QI)&occurringtime */
    { 0xB060, 0xDEDC, 5, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QII)&occurringtime */
    { 0xB070, 0xDEF7, 5, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QIII)&occurringtime */
    { 0xB080, 0xDF12, 5, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QIV)&occurringtime */
    { 0xB090, 0xDF2D, 5, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(+)&occurringtime */
    { 0xB0A0, 0xDF48, 5, 5, attribute(format_00, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(-)&occurringtime */
    { 0xFFFF, 0xDF63, 200, 1, attribute(format_00, notify_00, 0, N/A, 0, 1) }, /**< 预留100个字节，填加新的ID从这里分配 */
};
const uint16 CODE item_demand_num = sizeof(item_demand_tab) / sizeof(item_demand_tab[0]);

const struct file_t CODE item_log2_tab[] =
{
    { 0xF910, 0x06B8, 10, 254, attribute(format_00, notify_00, 0, 0, 1, 0) }, /**< 小时冻结 */
    { 0xF911, 0x06C2, 13, 62, attribute(format_00, notify_00, 0, 0, 1, 0) }, /**< 日冻结 */
    { 0xF912, 0x06CF, 7, 12, attribute(format_00, notify_00, 0, 0, 1, 0) }, /**< 月冻结 */
};

const struct file_t CODE item_energy_tab[] =
{
    { 0x9000, 0x0000, 4, 5, attribute(F_U32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相基础有功电能+0011 */
    { 0x9010, 0x0016, 4, 5, attribute(F_U32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相基础有功电能-0021 */
    { 0x9020, 0x002C, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相基础无功电能10051 */
    { 0x9030, 0x0042, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相基础无功电能20061 */
    { 0x9040, 0x0058, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相基础无功电能30071 */
    { 0x9050, 0x006E, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相基础无功电能40081 */
    { 0x9060, 0x0084, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相基础视在+0091 */
    { 0x9070, 0x009A, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相基础视在-00A1 */
    { 0x9080, 0x00B0, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相有功组合+ */
    { 0x9090, 0x00C6, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相有功组合- */
    { 0x90A0, 0x00DC, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相有功组合总 */
    { 0x90B0, 0x00F2, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相无功组合+0031 */
    { 0x90C0, 0x0108, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相无功组合-0041 */
    { 0x90D0, 0x011E, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相无功组合总 */
    { 0x90E0, 0x0134, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相无功组合 */
    { 0x90F0, 0x014A, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前A相视在 */
    { 0x9100, 0x0160, 4, 5, attribute(F_U32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相基础有功电能+0012 */
    { 0x9110, 0x0176, 4, 5, attribute(F_U32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相基础有功电能-0022 */
    { 0x9120, 0x018C, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相基础无功电能10052 */
    { 0x9130, 0x01A2, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相基础无功电能20062 */
    { 0x9140, 0x01B8, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相基础无功电能30072 */
    { 0x9150, 0x01CE, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相基础无功电能40082 */
    { 0x9160, 0x01E4, 4, 5, attribute(F_U32_KVAH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相基础视在+0092 */
    { 0x9170, 0x01FA, 4, 5, attribute(F_U32_KVAH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相基础视在-00A2 */
    { 0x9180, 0x0210, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相有功组合+ */
    { 0x9190, 0x0226, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相有功组合- */
    { 0x91A0, 0x023C, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相有功组合总 */
    { 0x91B0, 0x0252, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相无功组合+0032 */
    { 0x91C0, 0x0268, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相无功组合-0042 */
    { 0x91D0, 0x027E, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相无功组合总 */
    { 0x91E0, 0x0294, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相无功组合 */
    { 0x91F0, 0x02AA, 4, 5, attribute(F_U32_KVAH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前B相视在 */
    { 0x9200, 0x02C0, 4, 5, attribute(F_U32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相基础有功电能+0013 */
    { 0x9210, 0x02D6, 4, 5, attribute(F_U32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相基础有功电能-0023 */
    { 0x9220, 0x02EC, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相基础无功电能10053 */
    { 0x9230, 0x0302, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相基础无功电能20063 */
    { 0x9240, 0x0318, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相基础无功电能30073 */
    { 0x9250, 0x032E, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相基础无功电能40083 */
    { 0x9260, 0x0344, 4, 5, attribute(F_U32_KVAH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相基础视在+0093 */
    { 0x9270, 0x035A, 4, 5, attribute(F_U32_KVAH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相基础视在-00A3 */
    { 0x9280, 0x0370, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相有功组合+ */
    { 0x9290, 0x0386, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相有功组合- */
    { 0x92A0, 0x039C, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相有功组合总 */
    { 0x92B0, 0x03B2, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相无功组合+0033 */
    { 0x92C0, 0x03C8, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相无功组合-0043 */
    { 0x92D0, 0x03DE, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相无功组合总 */
    { 0x92E0, 0x03F4, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相无功组合 */
    { 0x92F0, 0x040A, 4, 5, attribute(F_U32_KVAH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前C相视在 */
    { 0x9300, 0x0420, 4, 5, attribute(F_U32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前基础总有功电能+0010 */
    { 0x9310, 0x0436, 4, 5, attribute(F_U32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前基础总有功电能-0020 */
    { 0x9320, 0x044C, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前基础总无功电能10050 */
    { 0x9330, 0x0462, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前基础总无功电能20060 */
    { 0x9340, 0x0478, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前基础总无功电能30070 */
    { 0x9350, 0x048E, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前基础总无功电能40080 */
    { 0x9360, 0x04A4, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前基础总视在+0090 */
    { 0x9370, 0x04BA, 4, 5, attribute(F_U32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前基础总视在-00A0 */
    { 0x9380, 0x04D0, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前有功总组合+0000 */
    { 0x9390, 0x04E6, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前有功总组合- */
    { 0x93A0, 0x04FC, 4, 5, attribute(F_I32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前有功总组合总 */
    { 0x93B0, 0x0512, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前无功总组合+0030 */
    { 0x93C0, 0x0528, 4, 5, attribute(F_I32_KVAH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前无功总组合-0040 */
    { 0x93D0, 0x053E, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前无功总组合总 */
    { 0x93E0, 0x0554, 4, 5, attribute(F_I32_KVARH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前无功总组合 */
    { 0x93F0, 0x056A, 4, 5, attribute(F_U32_KVAH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 当前视在总 */
    { 0x9400, 0x0580, 4, 5, attribute(F_U32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 月度有功用电量 */
    { 0x9500, 0x0596, 4, 5, attribute(F_U32_KWH_N2, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< 年度有功用电量 */
};

const struct file_t CODE item_Instantaneous_tab[] =
{
    { 0xC000, 0x0000, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时有功功率 */
    { 0xC001, 0x0006, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时无功功率 */
    { 0xC002, 0x000C, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时视在功率 */
    { 0xC003, 0x0012, 2, 1, attribute(F_U16_V_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时电压 */
    { 0xC004, 0x0016, 4, 1, attribute(F_I32_A_N3, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时电流 */
    { 0xC005, 0x001C, 2, 1, attribute(F_I16_COS_N3, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时功率因数 */
    { 0xC006, 0x0020, 2, 1, attribute(F_U16_ANGLE_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时压流角 */
    { 0xC007, 0x0024, 2, 1, attribute(F_U16_ANGLE_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬相角 */
    { 0xC010, 0x0028, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时有功功率 */
    { 0xC011, 0x002E, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时无功功率 */
    { 0xC012, 0x0034, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时视在功率 */
    { 0xC013, 0x003A, 2, 1, attribute(F_U16_V_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时电压 */
    { 0xC014, 0x003E, 4, 1, attribute(F_I32_A_N3, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时电流 */
    { 0xC015, 0x0044, 2, 1, attribute(F_I16_COS_N3, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时功率因数 */
    { 0xC016, 0x0048, 2, 1, attribute(F_U16_ANGLE_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时压流角 */
    { 0xC017, 0x004C, 2, 1, attribute(F_U16_ANGLE_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬相角 */
    { 0xC020, 0x0050, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时有功功率 */
    { 0xC021, 0x0056, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时无功功率 */
    { 0xC022, 0x005C, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时视在功率 */
    { 0xC023, 0x0062, 2, 1, attribute(F_U16_V_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时电压 */
    { 0xC024, 0x0066, 4, 1, attribute(F_I32_A_N3, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时电流 */
    { 0xC025, 0x006C, 2, 1, attribute(F_I16_COS_N3, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时功率因数 */
    { 0xC026, 0x0070, 2, 1, attribute(F_U16_ANGLE_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时压流角 */
    { 0xC027, 0x0074, 2, 1, attribute(F_U16_ANGLE_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬相角 */
    { 0xC030, 0x0078, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬时有功功率 */
    { 0xC031, 0x007E, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬时无功功率 */
    { 0xC032, 0x0084, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬时视在功率 */
    { 0xC033, 0x008A, 2, 1, attribute(F_U16_HZ_N2, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前瞬时频率 */
    { 0xC034, 0x008E, 4, 1, attribute(F_I32_A_N3, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前时钟电池电压 */
    { 0xC035, 0x0094, 2, 1, attribute(F_I16_COS_N3, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬时功率因数 */
    { 0xC036, 0x0098, 4, 1, attribute(F_I32_A_N3, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前停抄电池电压 */
    { 0xC037, 0x009E, 4, 1, attribute(F_I16_COS_N3, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前温度 */
    { 0xC100, 0x00A4, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时正向有功功率 */
    { 0xC101, 0x00AA, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时反向有功功率 */
    { 0xC102, 0x00B0, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时无功象限1功率 */
    { 0xC103, 0x00B6, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时无功象限2功率 */
    { 0xC104, 0x00BC, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时无功象限3功率 */
    { 0xC105, 0x00C2, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时无功象限4功率 */
    { 0xC106, 0x00C8, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬时正向视在功率 */
    { 0xC107, 0x00CE, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相瞬反向视在功率 */
    { 0xC108, 0x00D4, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相组合有功一功率 */
    { 0xC109, 0x00DA, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相组合有功二功率 */
    { 0xC10A, 0x00E0, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相组合有功三功率 */
    { 0xC10B, 0x00E6, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相组合无功一功率 */
    { 0xC10C, 0x00EC, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相组合无功二功率 */
    { 0xC10D, 0x00F2, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相组合无功三功率 */
    { 0xC10E, 0x00F8, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相组合无功四功率 */
    { 0xC110, 0x00FE, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时正向有功功率 */
    { 0xC111, 0x0104, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时反向有功功率 */
    { 0xC112, 0x010A, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时无功象限1功率 */
    { 0xC113, 0x0110, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时无功象限2功率 */
    { 0xC114, 0x0116, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时无功象限3功率 */
    { 0xC115, 0x011C, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时无功象限4功率 */
    { 0xC116, 0x0122, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬时正向视在功率 */
    { 0xC117, 0x0128, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相瞬反向视在功率 */
    { 0xC118, 0x012E, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相组合有功一功率 */
    { 0xC119, 0x0134, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相组合有功二功率 */
    { 0xC11A, 0x013A, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相组合有功三功率 */
    { 0xC11B, 0x0140, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相组合无功一功率 */
    { 0xC11C, 0x0146, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相组合无功二功率 */
    { 0xC11D, 0x014C, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相组合无功三功率 */
    { 0xC11E, 0x0152, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相组合无功四功率 */
    { 0xC120, 0x0158, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时正向有功功率 */
    { 0xC121, 0x015E, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时反向有功功率 */
    { 0xC122, 0x0164, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时无功象限1功率 */
    { 0xC123, 0x016A, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时无功象限2功率 */
    { 0xC124, 0x0170, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时无功象限3功率 */
    { 0xC125, 0x0176, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时无功象限4功率 */
    { 0xC126, 0x017C, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬时正向视在功率 */
    { 0xC127, 0x0182, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相瞬反向视在功率 */
    { 0xC128, 0x0188, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相组合有功一功率 */
    { 0xC129, 0x018E, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相组合有功二功率 */
    { 0xC12A, 0x0194, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相组合有功三功率 */
    { 0xC12B, 0x019A, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相组合无功一功率 */
    { 0xC12C, 0x01A0, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相组合无功二功率 */
    { 0xC12D, 0x01A6, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相组合无功三功率 */
    { 0xC12E, 0x01AC, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相组合无功四功率 */
    { 0xC130, 0x01B2, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬时正向有功功率 */
    { 0xC131, 0x01B8, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬时反向有功功率 */
    { 0xC132, 0x01BE, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬时无功象限1功率 */
    { 0xC133, 0x01C4, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬时无功象限2功率 */
    { 0xC134, 0x01CA, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬时无功象限3功率 */
    { 0xC135, 0x01D0, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬时无功象限4功率 */
    { 0xC136, 0x01D6, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬时正向视在功率 */
    { 0xC137, 0x01DC, 4, 1, attribute(F_I32_VA_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总瞬反向视在功率 */
    { 0xC138, 0x01E2, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总组合有功一功率 */
    { 0xC139, 0x01E8, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总组合有功二功率 */
    { 0xC13A, 0x01EE, 4, 1, attribute(F_I32_W_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总组合有功三功率 */
    { 0xC13B, 0x01F4, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总组合无功一功率 */
    { 0xC13C, 0x01FA, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总组合无功二功率 */
    { 0xC13D, 0x0200, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总组合无功三功率 */
    { 0xC13E, 0x0206, 4, 1, attribute(F_I32_var_N1, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总组合无功四功率 */
    { 0xC200, 0x020C, 4, 1, attribute(F_U32_Ah_N2, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前总安时数 */
    { 0xC210, 0x0212, 4, 1, attribute(F_U32_Ah_N2, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前A相安时数 */
    { 0xC220, 0x0218, 4, 1, attribute(F_U32_Ah_N2, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前B相安时数 */
    { 0xC230, 0x021E, 4, 1, attribute(F_U32_Ah_N2, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 当前C相安时数 */
    { 0xC500, 0x0224, 7, 1, attribute(format_00, notify_06, 	DEVICE_MEM_RTC, 1, 0, 1) }, /**< 当前时间日期 */
    { 0xC503, 0x022D, 4, 1, attribute(format_00, notify_06, 	DEVICE_MEM_RTC, 1, 0, 1) }, /**< 当前时间日期 */
    { 0xC600, 0x0233, 7, 1, attribute(format_00, notify_00, 	DEVICE_MEM_RTC, 1, 0, 1) }, /**< 当前时间日期 */
    { 0xC603, 0x023C, 4, 1, attribute(format_00, notify_00, 	DEVICE_MEM_RTC, 1, 0, 1) }, /**< 当前时间日期 */
    { 0xC700, 0x0242, 4, 1, attribute(format_00, notify_06, 	DEVICE_MEM_RTC, 1, 0, 1) }, /**< 电池使用时间 */
};

const struct file_t CODE item_disp_tab[] =
{
    { 0x6000, 0x0000, 1, 1, attribute(format_01, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 需量积算方式 */
    { 0x6001, 0x0003, 4, 1, attribute(format_18, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前正向有功需量 */
    { 0x6002, 0x0009, 4, 1, attribute(format_18, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前反向有功需量 */
    { 0x6003, 0x000F, 4, 1, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前组合无功1需量 */
    { 0x6004, 0x0015, 4, 1, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前组合无功2需量 */
    { 0x6005, 0x001B, 4, 1, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前第一象限无功需量 */
    { 0x6006, 0x0021, 4, 1, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前第二象限无功需量 */
    { 0x6007, 0x0027, 4, 1, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前第三象限无功需量 */
    { 0x6008, 0x002D, 4, 1, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前第四象限无功需量 */
    { 0x6009, 0x0033, 4, 1, attribute(format_20, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前需量正向视在需量 */
    { 0x600A, 0x0039, 4, 1, attribute(format_20, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前需量反向视在需量 */
    { 0x600B, 0x003F, 4, 1, attribute(format_18, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前有功需量 */
    { 0x600C, 0x0045, 4, 1, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前无功需量 */
    { 0x600D, 0x004B, 4, 1, attribute(format_20, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 当前视在需量 */
    { 0x6010, 0x0051, 8, 5, attribute(format_01, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 合相正向有功总及分费率最大需量及发生时间 */
    { 0x6020, 0x007B, 8, 5, attribute(format_01, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 合相反向有功总及分费率最大需量及发生时间 */
    { 0x6030, 0x00A5, 8, 5, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 合相组合无功1总及分费率最大需量及发生时间 */
    { 0x6040, 0x00CF, 8, 5, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 合相组合无功2总及分费率最大需量及发生时间 */
    { 0x6050, 0x00F9, 8, 5, attribute(format_02, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 合相第一象限总及分费率最大需量及发生时间 */
    { 0x6060, 0x0123, 8, 5, attribute(format_02, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 合相第二象限总及分费率最大需量及发生时间 */
    { 0x6070, 0x014D, 8, 5, attribute(format_02, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 合相第三象限总及分费率最大需量及发生时间 */
    { 0x6080, 0x0177, 8, 5, attribute(format_02, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 合相第四象限总及分费率最大需量及发生时间 */
    { 0x6090, 0x01A1, 8, 5, attribute(format_03, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 合相瞬时正向视在最大需量及发生时间 */
    { 0x60A0, 0x01CB, 8, 5, attribute(format_03, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 合相瞬时反向视在最大需量及发生时间 */
    { 0x6100, 0x01F5, 8, 255, attribute(0x00, 0x00, DEVICE_DEMAND, 1, 0, 1) }, /**< 虚拟的id */
    { 0x6200, 0x09EF, 128, 2, attribute(0x00, 0x00, DEVICE_DLT645	, 1, 0, 1) }, /**< 当前套费率 */
    { 0x6202, 0x0AF1, 64, 2, attribute(0x00, 0x00, 	DEVICE_DLT645	, 1, 0, 1) }, /**< 当前套阶梯值+阶梯电价+结算日 */
    { 0x6204, 0x0B73, 11, 1, attribute(0x00, 0x00, 	DEVICE_DLT645	, 1, 0, 1) }, /**< 电能表位置信息：经度纬度高度 */
    { 0x6205, 0x0B80, 6, 1, attribute(0x00, 0x00, 	DEVICE_DLT645	, 1, 0, 1) }, /**< dlt645电压数据块 */
    { 0x6206, 0x0B88, 9, 1, attribute(0x00, 0x00, 	DEVICE_DLT645	, 1, 0, 1) }, /**< dlt645电流数据块 */
    { 0x6207, 0x0B93, 12, 1, attribute(0x00, 0x00, 	DEVICE_DLT645	, 1, 0, 1) }, /**< 瞬时有功功率数据块 */
    { 0x6208, 0x0BA1, 12, 1, attribute(0x00, 0x00, 	DEVICE_DLT645	, 1, 0, 1) }, /**< 瞬时无功功率数据块 */
    { 0x6209, 0x0BAF, 12, 1, attribute(0x00, 0x00, 	DEVICE_DLT645	, 1, 0, 1) }, /**< 瞬时视在功率数据块 */
    { 0x620a, 0x0BBD, 8, 1, attribute(0x00, 0x00, 	DEVICE_DLT645	, 1, 0, 1) }, /**< 功率因数数据块 */
    { 0x620b, 0x0BC7, 6, 1, attribute(0x00, 0x00, 	DEVICE_DLT645	, 1, 0, 1) }, /**< 相角数据块 */
    { 0x620c, 0x0BCF, 50, 1, attribute(0x00, 0x00, 	DEVICE_DLT645	, 1, 0, 1) }, /**< 程序版本号 */
    { 0x620d, 0x0C03, 14, 1, attribute(0x00, 0x00, 	DEVICE_DLT645	, 1, 0, 1) }, /**< 电表运行状态字数据块 */
    { 0x6300, 0x0C13, 1, 1, attribute(format_00, notify_00, DEVICE_DISPLAY, 1, 0, 1) }, /**< 自动循环显示屏数读写操作 */
    { 0x6301, 0x0C16, 1, 1, attribute(format_00, notify_00, DEVICE_DISPLAY, 1, 0, 1) }, /**< 按键循环显示屏数读写操作 */
    { 0x6400, 0x0C19, 5, 255, attribute(format_00, notify_00, DEVICE_DISPLAY, 1, 0, 1) }, /**< 自动循环显示项内容读写操作 */
    { 0x6500, 0x1116, 5, 255, attribute(format_00, notify_00, DEVICE_DISPLAY, 1, 0, 1) }, /**< 按键循环显示项内容读写操作 */
    { 0x6600, 0x1613, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 接收继电器控制命令 */
    { 0x6601, 0x1616, 3, 1, attribute(format_13, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 控制命令错误信息字写-第一个字节固定为长度16 */
    { 0x6602, 0x161B, 3, 1, attribute(format_13, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 控制命令错误信息字读-第一个字节固定为长度16 */
    { 0x6603, 0x1620, 3, 1, attribute(format_13, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 控制命令执行状态字读-第一个字节固定为长度16 */
    { 0x6604, 0x1625, 2, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 继电器-命令状态读(通讯接口) */
    { 0x6605, 0x1629, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 继电器-当前控制回路错误标志 */
    { 0x6606, 0x162C, 2, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 继电器-告警状态 */
    { 0x6607, 0x1630, 2, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 保电状态 */
    { 0x6700, 0x1634, 4, 5, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 组合无功1总及分费率最大需量 */
    { 0x6710, 0x1652, 4, 5, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 组合无功2总及分费率最大需量 */
    { 0x6720, 0x1670, 4, 5, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 组合无功1总及分费率最大需量发生时间  */
    { 0x6730, 0x168E, 4, 5, attribute(format_19, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< 组合无功2总及分费率最大需量发生时间 */
    { 0x6F00, 0x16AC, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< A无功率反向 */
    { 0x6F01, 0x16AF, 1, 1, attribute(format_00, notify_00, DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A电压指示符 */
    { 0x6F02, 0x16B2, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 液晶A相指示反向指示 */
    { 0x6F03, 0x16B5, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 液晶A相指示正向指示 */
    { 0x6F04, 0x16B8, 1, 1, attribute(format_00, notify_00, DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A电流指示符 */
    { 0x6F10, 0x16BB, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< B无功率反向 */
    { 0x6F11, 0x16BE, 1, 1, attribute(format_00, notify_00, DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B电压指示符 */
    { 0x6F12, 0x16C1, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 液晶B相指示反向指示 */
    { 0x6F13, 0x16C4, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 液晶B相指示正向指示 */
    { 0x6F14, 0x16C7, 1, 1, attribute(format_00, notify_00, DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B电流指示符 */
    { 0x6F20, 0x16CA, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 总C无功率反向 */
    { 0x6F21, 0x16CD, 1, 1, attribute(format_00, notify_00, DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C电压指示符 */
    { 0x6F22, 0x16D0, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 液晶C相指示反向指示 */
    { 0x6F23, 0x16D3, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 液晶C相指示正向指示 */
    { 0x6F24, 0x16D6, 1, 1, attribute(format_00, notify_00, DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C电流指示符 */
    { 0x6F2F, 0x16D9, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 无功功率潮流反向 */
    { 0x6F30, 0x16DC, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 总无功率反向 */
    { 0x6F31, 0x16DF, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 电源异常 */
    { 0x6F32, 0x16E2, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 总有功率反向 */
    { 0x6F33, 0x16E5, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 低功耗状态下全失压发生标志 */
    { 0x6F34, 0x16E8, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 电压逆相序 */
    { 0x6F35, 0x16EB, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 电流逆相序 */
    { 0x6F36, 0x16EE, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 潮流反向 */
    { 0x6F37, 0x16F1, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 三相电流均低于5%IB */
    { 0x6F38, 0x16F4, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 三相电压均低于60%UN */
    { 0x6F39, 0x16F7, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 三相电压均低于68%UN */
    { 0x6F3A, 0x16FA, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 三相电流均高于5%IB */
    { 0x6F3B, 0x16FD, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 任意一相电压高于120%UN */
    { 0x6F3C, 0x1700, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 三相电压均高于60%UN */
    { 0x6F3D, 0x1703, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 停抄电池欠压 */
    { 0x6F3E, 0x1706, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< 时钟电池欠压 */
    { 0x6F3F, 0x1709, 1, 1, attribute(format_00, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ActiveQuadrant */
    { 0x6F40, 0x170C, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 液晶预跳闸(请购电)指示 */
    { 0x6F41, 0x170F, 1, 1, attribute(format_00, notify_00, 0x00, 1, 0, 1) }, /**< 液晶电池欠压 */
    { 0x6F42, 0x1712, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 继电器命令状态(显示接口) */
    { 0x6F43, 0x1715, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 继电器合闸允许状态 */
    { 0x6F44, 0x1718, 1, 1, attribute(format_00, notify_00, DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 液晶通讯符号 */
    { 0x6F45, 0x171B, 1, 1, attribute(format_00, notify_00, 0x00, 1, 0, 1) }, /**< 液晶信号强度 */
    { 0x6F46, 0x171E, 1, 1, attribute(format_00, notify_00, DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 液晶模块通信 */
    { 0x6F47, 0x1721, 1, 1, attribute(format_00, notify_00, 0x00, 1, 0, 1) }, /**< 液晶红外认证成功 */
    { 0x6F48, 0x1724, 1, 1, attribute(format_00, notify_00, DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 液晶红外通信中 */
    { 0x6F49, 0x1727, 1, 1, attribute(format_00, notify_00, DEVICE_ESAM, 1, 0, 1) }, /**< 液晶挂起状态 */
    { 0x6F4A, 0x172A, 1, 1, attribute(format_00, notify_00, DEVICE_ESAM, 1, 0, 1) }, /**< 液晶读卡结果指示 */
    { 0x6F4B, 0x172D, 1, 1, attribute(format_00, notify_02, DEVICE_METER	, 1, 0, 1) }, /**< 点亮背光2秒 */
    { 0x6F4C, 0x1730, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 预跳闸(请购电)指示(运行状态字) */
    { 0x6F4D, 0x1733, 1, 1, attribute(format_00, notify_00, DEVICE_TARIFF	, 1, 0, 1) }, /**< 运行当前套时段表标志 */
    { 0x6F4E, 0x1736, 1, 1, attribute(format_00, notify_00, DEVICE_TARIFF	, 1, 0, 1) }, /**< 运行备用套时段表标志 */
    { 0x6F4F, 0x1739, 1, 1, attribute(format_00, notify_00, DEVICE_ALARM_STATUS, 1, 0, 1) }, /**< 当前报警状态 */
    { 0x6F50, 0x173C, 1, 1, attribute(format_00, notify_00, DEVICE_ESAM, 1, 0, 1) }, /**< 液晶测试秘钥状态 */
    { 0x6F51, 0x173F, 1, 1, attribute(format_00, notify_00, DEVICE_ESAM, 1, 0, 1) }, /**< 安全认证(应用连接)状态，0:未连接；1:已连接 */
    { 0x6F52, 0x1742, 1, 1, attribute(format_00, notify_00, DEVICE_DLT698, 1, 0, 1) }, /**< 明文合闸密码错误 */
    { 0x6F53, 0x1745, 1, 1, attribute(format_00, notify_00, DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 液晶逆相序显示状态 */
    { 0x6F54, 0x1748, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 继电器命令状态(运行状态) */
    { 0x6F55, 0x174B, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< ESAM自检状态:0:正常；1:损坏 */
    { 0x6F56, 0x174E, 1, 1, attribute(format_00, notify_00, DEVICE_ESAM, 1, 0, 1) }, /**< 液晶读卡指示 */
    { 0x6F57, 0x1751, 1, 1, attribute(format_00, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 液晶透支状态指示 */
    { 0x6F5C, 0x1754, 1, 1, attribute(format_00, notify_00, DEVICE_TARIFF , 1, 0, 1) }, /**< 备用套时段表等待切换标志1--等待切换 */
    { 0x6F5D, 0x1757, 1, 1, attribute(format_00, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 当前费率电价方案1--当前套 */
    { 0x6F5E, 0x175A, 1, 1, attribute(format_00, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 当前费率电价方案1--备用套 */
    { 0x6F5F, 0x175D, 1, 1, attribute(format_00, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 当前阶梯电价方案1--当前套 */
    { 0x6F60, 0x1760, 1, 1, attribute(format_00, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 当前阶梯电价方案1--备用套 */
    { 0x6F61, 0x1763, 1, 1, attribute(format_00, notify_00, DEVICE_TARIFF , 1, 0, 1) }, /**< 费率编号(费率号1到8) */
    { 0x6F62, 0x1766, 1, 1, attribute(format_00, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 阶梯电价编号 */
    { 0x6F63, 0x1769, 1, 1, attribute(format_00, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 预付费报警状态 */
    { 0x6F64, 0x176C, 4, 1, attribute(format_00, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 当前RAM钱包剩余金额--(预付费钱包扣减专用double-long-signed) */
    { 0x6F65, 0x1772, 2, 1, attribute(format_00, notify_00, 0x00, 1, 0, 1) }, /**< 红外认证剩余时长 */
    { 0x6F66, 0x1776, 4, 1, attribute(format_00, notify_00, 0x00, 1, 0, 1) }, /**< 远程身份认证剩余时长 */
    { 0x6F67, 0x177C, 2, 1, attribute(format_00, notify_00, 0x00, 1, 0, 1) }, /**< 通讯MAC连续错误锁定剩余时长 */
    { 0x6F68, 0x1780, 1, 1, attribute(format_00, notify_00, 0x00, 1, 0, 1) }, /**< 异常插卡错误信息字 */
    { 0x6F69, 0x1783, 5, 1, attribute(format_00, notify_00, 0x00, 1, 0, 1) }, /**< 异常插卡操作命令头 */
    { 0x6F6A, 0x178A, 2, 1, attribute(format_00, notify_00, 0x00, 1, 0, 1) }, /**< 异常插卡错误响应状态 */
    { 0x6F6B, 0x178E, 1, 1, attribute(format_00, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 辅助阶梯电价编号(与0x6F62共同组成阶梯电价1~7显示) */
    { 0x6F6D, 0x1791, 1, 1, attribute(format_00, notify_01, DEVICE_METER	, 1, 0, 1) }, /**< 费率切换 */
    { 0x6F70, 0x1794, 1, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 清零电压统计数据 */
    { 0x6F71, 0x1797, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当日--总电压统计数据 */
    { 0x6F72, 0x17B0, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当日--A电压统计数据 */
    { 0x6F73, 0x17C9, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当日--B电压统计数据 */
    { 0x6F74, 0x17E2, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当日--C电压统计数据 */
    { 0x6F75, 0x17FB, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当月--总电压统计数据 */
    { 0x6F76, 0x1814, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当月--A电压统计数据 */
    { 0x6F77, 0x182D, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当月--B电压统计数据 */
    { 0x6F78, 0x1846, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当月--C电压统计数据 */
    { 0x6F79, 0x185F, 2, 1, attribute(format_11, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 当前电压不平衡率 */
    { 0x6F7A, 0x1863, 2, 1, attribute(format_11, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 当前电流不平衡率 */
    { 0x6F7B, 0x1867, 23, 1, attribute(format_00, notify_00, DEVICE_CARD_APPLY, 1, 0, 1) }, /**< 异常插卡标准事件记录信息														 */
    { 0x6F80, 0x1880, 1, 1, attribute(format_00, notify_02, 	DEVICE_METER	, 1, 0, 1) }, /**< 红外唤醒背光命令 */
    { 0x6F81, 0x1883, 1, 1, attribute(format_00, notify_02, 	DEVICE_METER	, 1, 0, 1) }, /**< 按键唤醒背光命令 */
    { 0x6F82, 0x1886, 1, 1, attribute(format_00, notify_02, 	DEVICE_METER	, 1, 0, 1) }, /**< 插卡唤醒背光命令 */
    { 0x6F85, 0x1889, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当日--总电压统计变量数据 */
    { 0x6F86, 0x18A2, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当日--A电压统计变量数据 */
    { 0x6F87, 0x18BB, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当日--B电压统计变量数据 */
    { 0x6F88, 0x18D4, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当日--C电压统计变量数据 */
    { 0x6F89, 0x18ED, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当月--总电压统计变量数据 */
    { 0x6F8A, 0x1906, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当月--A电压统计变量数据 */
    { 0x6F8B, 0x191F, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当月--B电压统计变量数据 */
    { 0x6F8C, 0x1938, 23, 1, attribute(format_00, notify_00, DEVICE_STATISTIC, 1, 0, 1) }, /**< 当月--C电压统计变量数据 */
    { 0x6F90, 0x1951, 1, 1, attribute(format_00, notify_01, 	DEVICE_METER	, 1, 0, 1) }, /**< 格式化C盘数据 */
    { 0x6F91, 0x1954, 1, 1, attribute(format_00, notify_01, 	DEVICE_METER	, 1, 0, 1) }, /**< 格式化D盘数据 */
    { 0x6F92, 0x1957, 1, 1, attribute(format_00, notify_01, 	DEVICE_METER	, 1, 0, 1) }, /**< 格式化E盘数据 */
    { 0x6F93, 0x195A, 1, 1, attribute(format_00, notify_01, 	DEVICE_METER	, 1, 0, 1) }, /**< 格式化F盘数据 */
    { 0x6F94, 0x195D, 2, 1, attribute(format_00, notify_01, 	DEVICE_METER	, 1, 0, 1) }, /**< 获取程序校验和 */
    { 0x6F98, 0x1961, 1, 1, attribute(format_00, notify_02, 	DEVICE_METER	, 1, 0, 1) }, /**< 成功执行参数预制卡(钱包初始化)操作后清零通知 */
    { 0x6F99, 0x1964, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 成功执行参数预制卡(钱包初始化)操作后继电器命令清除动作 */
    { 0x6F9A, 0x1967, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 充值后结束跳闸自动恢复命令操作 */
    { 0x6FA0, 0x196A, 3, 7, attribute(format_13, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 表计运行状态字1~7 */
    { 0x6FA7, 0x1981, 3, 1, attribute(format_13, notify_00, DEVICE_CARD_APPLY, 1, 0, 1) }, /**< 插卡状态字 */
    { 0x6FA8, 0x1986, 1, 1, attribute(format_13, notify_00, DEVICE_CARD_APPLY, 1, 0, 1) }, /**< 插卡异常代码 */
    { 0x6FA9, 0x1989, 1, 1, attribute(format_00, notify_03, 	DEVICE_METER	, 1, 0, 1) }, /**< 异常插卡代码显示 */
    { 0x6FAA, 0x198C, 1, 1, attribute(format_00, notify_03, 	DEVICE_METER	, 1, 0, 1) }, /**< 读卡成功后剩余金额显示 */
    { 0x6FB0, 0x198F, 0, 1, attribute(format_00, notify_01, 0x00, 1, 0, 1) }, /**< 命令下翻 */
    { 0x6FB1, 0x1991, 0, 1, attribute(format_00, notify_01, 0x00, 1, 0, 1) }, /**< 命令上翻 */
    { 0x6FB2, 0x1993, 0, 1, attribute(format_00, notify_01, 0x00, 1, 0, 1) }, /**< 命令全显 */
    { 0x6FB3, 0x1995, 0, 1, attribute(format_00, notify_01, 0x00, 1, 0, 1) }, /**< 命令查看显示项 */
    { 0x6FC0, 0x1997, 5, 1, attribute(format_00, notify_00, 	DEVICE_METER	, 1, 0, 1) }, /**< 模拟停电时间 */
    { 0x6FC1, 0x199E, 2, 1, attribute(format_00, notify_00, DEVICE_ESAM, 1, 0, 1) }, /**< 应用连接前ESAM电源打开时间 */
    { 0x6FC2, 0x19A2, 1, 1, attribute(format_00, notify_00, DEVICE_ESAM, 1, 0, 1) }, /**< ESAM电源关闭状态0:关闭；1:打开 */
    { 0x6FD0, 0x19A5, 4, 1, attribute(format_00, notify_00, 	DEVICE_PREPAY, 1, 0, 1) }, /**< 钱包预制 */
    { 0x6FD1, 0x19AB, 4, 1, attribute(format_00, notify_00, 	DEVICE_PREPAY, 1, 0, 1) }, /**< 钱包退费 */
    { 0x6FD2, 0x19B1, 4, 1, attribute(format_00, notify_00, 	DEVICE_PREPAY, 1, 0, 1) }, /**< 钱包充值 */
    { 0x6FD3, 0x19B7, 4, 1, attribute(format_00, notify_00, 	DEVICE_PREPAY, 1, 0, 1) }, /**< 剩余金额--(协议变量获取double-long-unsigned) */
    { 0x6FD4, 0x19BD, 4, 1, attribute(format_00, notify_00, 	DEVICE_PREPAY, 1, 0, 1) }, /**< 透支金额--(协议变量获取double-long-unsigned) */
    { 0x6FD5, 0x19C3, 4, 1, attribute(format_00, notify_00, 	DEVICE_PREPAY, 1, 0, 1) }, /**< 当前电价--(协议变量获取double-long-unsigned) */
    { 0x6FD6, 0x19C9, 4, 1, attribute(format_00, notify_00, 	DEVICE_PREPAY, 1, 0, 1) }, /**< 当前费率电价--(协议变量获取double-long-unsigned) */
    { 0x6FD7, 0x19CF, 4, 1, attribute(format_00, notify_00, 	DEVICE_PREPAY, 1, 0, 1) }, /**< 当前阶梯电价--(协议变量获取double-long-unsigned) */
    { 0x6FD8, 0x19D5, 1, 1, attribute(format_00, notify_00, 	DEVICE_CARD_APPLY, 1, 0, 1) }, /**< 本地开户状态 */
    { 0x6FD9, 0x19D8, 1, 1, attribute(format_00, notify_00, 	DEVICE_CARD_APPLY, 1, 0, 1) }, /**< 远程开户状态 */
    { 0x6FDA, 0x19DB, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 本地拉合闸操作--(预付费模块控制) */
    { 0x6FDB, 0x19DE, 4, 1, attribute(format_00, notify_00, 	DEVICE_CARD_APPLY, 1, 0, 1) }, /**< 插卡前剩余金额--显示数据获取 */
    { 0x6FDC, 0x19E4, 4, 1, attribute(format_00, notify_00, 	DEVICE_CARD_APPLY, 1, 0, 1) }, /**< 插卡后剩余金额--显示数据获取 */
    { 0x6FDD, 0x19EA, 1, 1, attribute(format_00, notify_00, 	DEVICE_PREPAY, 1, 0, 1) }, /**< 透支状态--运行状态读取 */
    { 0x6FDE, 0x19ED, 1, 1, attribute(format_00, notify_00, 	DEVICE_PREPAY, 1, 0, 1) }, /**< 本地预跳闸状态--运行状态读取 */
    { 0x6FDF, 0x19F0, 12, 1, attribute(format_00, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 当前剩余金额+购电次数(tag)--冻结、结算捕获对象读取 */
    { 0x6FE0, 0x19FE, 5, 1, attribute(format_00, notify_00, 	DEVICE_CARD_APPLY, 1, 0, 1) }, /**< 购电前剩余金额 */
    { 0x6FE1, 0x1A05, 5, 1, attribute(format_00, notify_00, 	DEVICE_CARD_APPLY, 1, 0, 1) }, /**< 购电后剩余金额 */
    { 0x6FE2, 0x1A0C, 5, 1, attribute(format_00, notify_00, 	DEVICE_CARD_APPLY, 1, 0, 1) }, /**< 购电前累计购电金额 */
    { 0x6FE3, 0x1A13, 1, 1, attribute(format_00, notify_00, 	DEVICE_CARD_APPLY, 1, 0, 1) }, /**< 成功执行参数预制卡(钱包初始化)操作后购电记录标志 */
    { 0x6FE4, 0x1A16, 4, 1, attribute(F_U32_KWH_N2, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 当前结算模式下阶梯用电量--阶梯结算冻结捕获对象 */
    { 0x6FE5, 0x1A1C, 4, 1, attribute(format_00, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< 当前结算模式获取--阶梯结算使用 */
    { 0x6FF0, 0x1A1C, 1, 1, attribute(format_00, notify_00, DEVICE_METER, 1, 0, 1) }, /**< 电能表表型获取 */
};

const struct file_t CODE item_virtual_tab[] =
{
    { 0x7000, 0x0000, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 组合有功电能0x93A0 */
    { 0x7001, 0x001D, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 正向有功电能0x9300 */
    { 0x7002, 0x003A, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A */
    { 0x7003, 0x0057, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B */
    { 0x7004, 0x0074, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C */
    { 0x7005, 0x0091, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 反向有功电能0x9310 */
    { 0x7006, 0x00AE, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A */
    { 0x7007, 0x00CB, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B */
    { 0x7008, 0x00E8, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C */
    { 0x7009, 0x0105, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 组合无功1电能0x93B0 */
    { 0x700A, 0x0122, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A */
    { 0x700B, 0x013F, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B */
    { 0x700C, 0x015C, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C */
    { 0x700D, 0x0179, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 组合无功2电能0x93C0 */
    { 0x700E, 0x0196, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A */
    { 0x700F, 0x01B3, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B */
    { 0x7010, 0x01D0, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C */
    { 0x7011, 0x01ED, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 第一象限无功电能0x9320 */
    { 0x7012, 0x020A, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A */
    { 0x7013, 0x0227, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B */
    { 0x7014, 0x0244, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C */
    { 0x7015, 0x0261, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 第二象限无功电能0x9330 */
    { 0x7016, 0x027E, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A */
    { 0x7017, 0x029B, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B */
    { 0x7018, 0x02B8, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C */
    { 0x7019, 0x02D5, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 第三象限无功电能0x9340 */
    { 0x701A, 0x02F2, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A */
    { 0x701B, 0x030F, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B */
    { 0x701C, 0x032C, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C */
    { 0x701D, 0x0349, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 第四象限无功电能0x9350 */
    { 0x701E, 0x0366, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A */
    { 0x701F, 0x0383, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B */
    { 0x7020, 0x03A0, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C */
    { 0x7021, 0x03BD, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 正向视在电能0x9360 */
    { 0x7022, 0x03DA, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A */
    { 0x7023, 0x03F7, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B */
    { 0x7024, 0x0414, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C */
    { 0x7025, 0x0431, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 反向视在电能0x9370 */
    { 0x7026, 0x044E, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A */
    { 0x7027, 0x046B, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B */
    { 0x7028, 0x0488, 27, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C */
    { 0x7100, 0x04A5, 77, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相正向有功总及分费率最大需量及发生时间 */
    { 0x7101, 0x04F4, 77, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相反向有功总及分费率最大需量及发生时间 */
    { 0x7102, 0x0543, 77, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相组合无功1总及分费率最大需量及发生时间 */
    { 0x7103, 0x0592, 77, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相组合无功2总及分费率最大需量及发生时间 */
    { 0x7104, 0x05E1, 77, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第一象限总及分费率最大需量及发生时间 */
    { 0x7105, 0x0630, 77, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第二象限总及分费率最大需量及发生时间 */
    { 0x7106, 0x067F, 77, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第三象限总及分费率最大需量及发生时间 */
    { 0x7107, 0x06CE, 77, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第四象限总及分费率最大需量及发生时间 */
    { 0x7110, 0x071D, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相正向有功总最大需量及发生时间 */
    { 0x7111, 0x072E, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相反向有功总最大需量及发生时间 */
    { 0x7112, 0x073F, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相组合无功1总最大需量及发生时间 */
    { 0x7113, 0x0750, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相组合无功2总最大需量及发生时间 */
    { 0x7114, 0x0761, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第一象限总最大需量及发生时间 */
    { 0x7115, 0x0772, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第二象限总最大需量及发生时间 */
    { 0x7116, 0x0783, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第三象限总最大需量及发生时间 */
    { 0x7117, 0x0794, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第四象限总最大需量及发生时间 */
    { 0x7120, 0x07A5, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A相正向有功总最大需量及发生时间 */
    { 0x7121, 0x07B6, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A相反向有功总最大需量及发生时间 */
    { 0x7122, 0x07C7, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A相组合无功1总最大需量及发生时间 */
    { 0x7123, 0x07D8, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A相组合无功2总最大需量及发生时间 */
    { 0x7124, 0x07E9, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A相第一象限总最大需量及发生时间 */
    { 0x7125, 0x07FA, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A相第二象限总最大需量及发生时间 */
    { 0x7126, 0x080B, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A相第三象限总最大需量及发生时间 */
    { 0x7127, 0x081C, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< A相第四象限总最大需量及发生时间 */
    { 0x7130, 0x082D, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B相正向有功总最大需量及发生时间 */
    { 0x7131, 0x083E, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B相反向有功总最大需量及发生时间 */
    { 0x7132, 0x084F, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B相组合无功1总最大需量及发生时间 */
    { 0x7133, 0x0860, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B相组合无功2总最大需量及发生时间 */
    { 0x7134, 0x0871, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B相第一象限总最大需量及发生时间 */
    { 0x7135, 0x0882, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B相第二象限总最大需量及发生时间 */
    { 0x7136, 0x0893, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B相第三象限总最大需量及发生时间 */
    { 0x7137, 0x08A4, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< B相第四象限总最大需量及发生时间 */
    { 0x7140, 0x08B5, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C相正向有功总最大需量及发生时间 */
    { 0x7141, 0x08C6, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C相反向有功总最大需量及发生时间 */
    { 0x7142, 0x08D7, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C相组合无功1总最大需量及发生时间 */
    { 0x7143, 0x08E8, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C相组合无功2总最大需量及发生时间 */
    { 0x7144, 0x08F9, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C相第一象限总最大需量及发生时间 */
    { 0x7145, 0x090A, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C相第二象限总最大需量及发生时间 */
    { 0x7146, 0x091B, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C相第三象限总最大需量及发生时间 */
    { 0x7147, 0x092C, 15, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< C相第四象限总最大需量及发生时间 */
    { 0x7150, 0x093D, 13, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相正向有功总最大需量及发生时间 */
    { 0x7151, 0x094C, 13, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相反向有功总最大需量及发生时间 */
    { 0x7152, 0x095B, 13, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相组合无功1总最大需量及发生时间 */
    { 0x7153, 0x096A, 13, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相组合无功2总最大需量及发生时间 */
    { 0x7154, 0x0979, 13, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第一象限总最大需量及发生时间 */
    { 0x7155, 0x0988, 13, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第二象限总最大需量及发生时间 */
    { 0x7156, 0x0997, 13, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第三象限总最大需量及发生时间 */
    { 0x7157, 0x09A6, 13, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 合相第四象限总最大需量及发生时间 */
    { 0x7200, 0x09B5, 11, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 电压A,B,C */
    { 0x7201, 0x09C2, 17, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 电流A,B,C */
    { 0x7202, 0x09D5, 11, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 电压相角AB,BC,CA */
    { 0x7203, 0x09E2, 11, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 电压电流相角AB,BC,CA */
    { 0x7204, 0x09EF, 0, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 电压波形失真度A,B,C */
    { 0x7205, 0x09F1, 0, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 电流波形失真度A,B,C */
    { 0x7206, 0x09F3, 22, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 有功功率A,B,C */
    { 0x7207, 0x0A0B, 22, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 无功功率A,B,C */
    { 0x7208, 0x0A23, 22, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 视在功率A,B,C */
    { 0x7209, 0x0A3B, 22, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 一分钟平均有功功率A,B,C */
    { 0x720A, 0x0A53, 22, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 一分钟平均无功功率A,B,C */
    { 0x720B, 0x0A6B, 22, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 一分钟平均视在功率A,B,C */
    { 0x720C, 0x0A83, 14, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 功率因数A,B,C */
    { 0x720D, 0x0A93, 22, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 安时值：总，A,B,C */
    { 0x720E, 0x0AAB, 0, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< （当前）钱包文件：剩余金额+购电次数 */
    { 0x720F, 0x0AAD, 0, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 日最大有功功率及发生时间 */
    { 0x7210, 0x0AAF, 0, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 月最大有功功率及发生时间 */
    { 0x7410, 0x0AB1, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表开盖事件 */
    { 0x7411, 0x0AB7, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表开端钮盒事件 */
    { 0x7412, 0x0ABD, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表全失压事件 */
    { 0x7413, 0x0AC3, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表恒定磁场干扰事件 */
    { 0x7414, 0x0AC9, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表负荷开关误动作事件 */
    { 0x7415, 0x0ACF, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表电源异常事件 */
    { 0x7416, 0x0AD5, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表掉电事件 */
    { 0x7417, 0x0ADB, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表辅助电源掉电事件 */
    { 0x7418, 0x0AE1, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表电压逆相序事件 */
    { 0x7419, 0x0AE7, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表电流逆相序事件 */
    { 0x741A, 0x0AED, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相电能表失压事件 */
    { 0x741B, 0x0AF3, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相电能表失压事件 */
    { 0x741C, 0x0AF9, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相电能表失压事件 */
    { 0x741D, 0x0AFF, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相电能表欠压事件 */
    { 0x741E, 0x0B05, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相电能表欠压事件 */
    { 0x741F, 0x0B0B, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相电能表欠压事件 */
    { 0x7420, 0x0B11, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相电能表过压事件 */
    { 0x7421, 0x0B17, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相电能表过压事件 */
    { 0x7422, 0x0B1D, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相电能表过压事件 */
    { 0x7423, 0x0B23, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相电能表断相事件 */
    { 0x7424, 0x0B29, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相电能表断相事件 */
    { 0x7425, 0x0B2F, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相电能表断相事件 */
    { 0x7426, 0x0B35, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相电能表失流事件 */
    { 0x7427, 0x0B3B, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相电能表失流事件 */
    { 0x7428, 0x0B41, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相电能表失流事件 */
    { 0x7429, 0x0B47, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相电能表过流事件 */
    { 0x742A, 0x0B4D, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相电能表过流事件 */
    { 0x742B, 0x0B53, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相电能表过流事件 */
    { 0x742C, 0x0B59, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相电能表断流事件 */
    { 0x742D, 0x0B5F, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相电能表断流事件 */
    { 0x742E, 0x0B65, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相电能表断流事件 */
    { 0x742F, 0x0B6B, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相电能表功率反向事件 */
    { 0x7430, 0x0B71, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相电能表功率反向事件 */
    { 0x7431, 0x0B77, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相电能表功率反向事件 */
    { 0x7432, 0x0B7D, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相电能表过载事件 */
    { 0x7433, 0x0B83, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相电能表过载事件 */
    { 0x7434, 0x0B89, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相电能表过载事件 */
    { 0x7435, 0x0B8F, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表电流不平衡事件 */
    { 0x7436, 0x0B95, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表电流严重不平衡事件 */
    { 0x7437, 0x0B9B, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 电能表电压不平衡事件 */
    { 0x7438, 0x0BA1, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 正向有功需量超限事件 */
    { 0x7439, 0x0BA7, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 反向有功需量超限事件 */
    { 0x743A, 0x0BAD, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 1象限无功需量超限事件 */
    { 0x743B, 0x0BB3, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 2象限无功需量超限事件 */
    { 0x743C, 0x0BB9, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 3象限无功需量超限事件 */
    { 0x743D, 0x0BBF, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 4象限无功需量超限事件 */
    { 0x743E, 0x0BC5, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 功率因数超下限事件 */
    { 0x7450, 0x0BCB, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 其他事件的累计发生时间 */
    { 0x7800, 0x0BD1, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 正向有功总电能 */
    { 0x7801, 0x0BD7, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 正向有功尖电能 */
    { 0x7802, 0x0BDD, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 正向有功峰电能 */
    { 0x7803, 0x0BE3, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 正向有功平电能 */
    { 0x7804, 0x0BE9, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 正向有功谷电能 */
    { 0x7805, 0x0BEF, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 正向有功总最大需量 */
    { 0x7806, 0x0BF5, 3, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 正向有功总最大需量发生日期 */
    { 0x7807, 0x0BFA, 2, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 正向有功总最大需量发生时间 */
    { 0x7808, 0x0BFE, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 反向有功总电能 */
    { 0x7809, 0x0C04, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 反向有功尖电能 */
    { 0x780A, 0x0C0A, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 反向有功峰电能 */
    { 0x780B, 0x0C10, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 反向有功平电能 */
    { 0x780C, 0x0C16, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 反向有功谷电能 */
    { 0x780D, 0x0C1C, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 反向有功总最大需量 */
    { 0x780E, 0x0C22, 3, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 反向有功总最大需量发生日期 */
    { 0x780F, 0x0C27, 2, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 反向有功总最大需量发生时间 */
    { 0x7810, 0x0C2B, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 第1象限无功总电能 */
    { 0x7811, 0x0C31, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 第2象限无功总电能 */
    { 0x7812, 0x0C37, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 第3象限无功总电能 */
    { 0x7813, 0x0C3D, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< 第4象限无功总电能 */
    { 0x7900, 0x0C43, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相失压起始时刻正向有功电能 */
    { 0x7901, 0x0C49, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相失压结束时刻正向有功电能 */
    { 0x7902, 0x0C4F, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相失压起始时刻反向有功电能 */
    { 0x7903, 0x0C55, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< A相失压结束时刻反向有功电能 */
    { 0x7910, 0x0C5B, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相失压起始时刻正向有功电能 */
    { 0x7911, 0x0C61, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相失压结束时刻正向有功电能 */
    { 0x7912, 0x0C67, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相失压起始时刻反向有功电能 */
    { 0x7913, 0x0C6D, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< B相失压结束时刻反向有功电能 */
    { 0x7920, 0x0C73, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相失压起始时刻正向有功电能 */
    { 0x7921, 0x0C79, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相失压结束时刻正向有功电能 */
    { 0x7922, 0x0C7F, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相失压起始时刻反向有功电能 */
    { 0x7923, 0x0C85, 4, 1, attribute(format_00, notify_00, 	DEVICE_RUNSTATUS, 1, 0, 1) }, /**< C相失压结束时刻反向有功电能 */
    { 0x7e02, 0x0C8B, 3, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 当前正向有功总最大需量发生日期 */
    { 0x7e03, 0x0C90, 2, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 当前正向有功总最大需量发生时间 */
    { 0x7e04, 0x0C94, 3, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 当前反向有功总最大需量发生日期 */
    { 0x7e05, 0x0C99, 2, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 当前反向有功总最大需量发生时间 */
    { 0x7e06, 0x0C9D, 2, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 通信地址高4位 */
    { 0x7e07, 0x0CA1, 4, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 通信地址低8位 */
    { 0x7e0A, 0x0CA7, 3, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 最近一次失压起始日期 */
    { 0x7e0B, 0x0CAC, 2, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 最近一次失压起始时间 */
    { 0x7e0C, 0x0CB0, 3, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 最近一次失压结束日期 */
    { 0x7e0D, 0x0CB5, 2, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 最近一次失压结束时间 */
    { 0x7e0e, 0x0CB9, 4, 1, attribute(format_15, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 总失压次数	 */
    { 0x7e0f, 0x0CBF, 4, 1, attribute(format_15, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 总失压累计时间 */
    { 0x7F00, 0x0CC5, 7, 1, attribute(format_00, notify_00, 	DEVICE_DLT698, 1, 0, 1) }, /**< 电能表事件清零OMD列表 */
};

const struct file_t CODE item_char_device_tab[] =
{
    { 0x1001, 0x0000, 1, 1, attribute(format_00, notify_00, DEVICE_COVER, 1, 0, 1) }, /**< 表盖开合状态 */
    { 0x1002, 0x0003, 1, 1, attribute(format_00, notify_00, DEVICE_TERM, 1, 0, 1) }, /**< 端钮开合盖状态 */
    { 0x1003, 0x0006, 1, 1, attribute(format_00, notify_00, DEVICE_MAGNETIC, 1, 0, 1) }, /**< 磁场干扰状态 */
    { 0x1004, 0x0009, 1, 1, attribute(format_00, notify_00, DEVICE_PAGE_UP, 1, 0, 1) }, /**< 磁场干扰状态 */
    { 0x1050, 0x000C, 7, 1, attribute(format_00, notify_00, DEVICE_RTC, 1, 0, 1) }, /**< 时钟文件ID */
    { 0x1060, 0x0015, 232, 1, attribute(format_00, notify_00, DEVICE_IR, 1, 0, 1) }, /**< 光电或者红外文件ID */
    { 0x1061, 0x00FF, 544, 1, attribute(format_00, notify_00, DEVICE_RS4851, 1, 0, 1) }, /**< RS485文件ID */
    { 0x1062, 0x0321, 286, 1, attribute(format_00, notify_00, DEVICE_PLC, 1, 0, 1) }, /**< PLC文件ID */
    { 0x1063, 0x0441, 1, 1, attribute(format_00, notify_00, DEVICE_EVEN_OUT, 1, 0, 1) }, /**< 事件上报evenout */
    { 0x1070, 0x0444, 1, 1, attribute(format_00, notify_00, DEVICE_BACKLIGHT, 1, 0, 1) }, /**< 背光 */
    { 0x1080, 0x0447, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< 继电器 */
    { 0x1081, 0x044A, 1, 1, attribute(format_00, notify_00, DEVICE_RELAY_LED, 1, 0, 1) }, /**< 继电器指示灯 */
    { 0x1082, 0x044D, 1, 1, attribute(format_00, notify_00, DEVICE_LEVEL_RELAY, 1, 0, 1) }, /**< 报警干簧继电器 */
    { 0x1083, 0x0450, 1, 1, attribute(format_00, notify_00, DEVICE_BUZZER, 1, 0, 1) }, /**< 蜂鸣器 */
};
