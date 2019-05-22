
const struct item_t CODE item_display_history_tab[] =
{
    { 0x0100, 0x0000, 4, 60, fs_attribute(F_U32_W, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 1.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0140, 0x00F2, 4, 60, fs_attribute(F_U32_W, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 2.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0180, 0x01E4, 4, 60, fs_attribute(F_U32_VAR, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 3.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x01C0, 0x02D6, 4, 60, fs_attribute(F_U32_VAR, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 4.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0200, 0x03C8, 4, 60, fs_attribute(F_U32_VAR, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 5.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0240, 0x04BA, 4, 60, fs_attribute(F_U32_VAR, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 6.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0280, 0x05AC, 4, 60, fs_attribute(F_U32_VAR, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 7.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x02C0, 0x069E, 4, 60, fs_attribute(F_U32_VAR, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 8.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0300, 0x0790, 4, 60, fs_attribute(F_U32_VA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 9.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0340, 0x0882, 4, 60, fs_attribute(F_U32_VA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 10.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0380, 0x0974, 4, 60, fs_attribute(F_U32_W, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 15.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x03C0, 0x0A66, 4, 60, fs_attribute(F_U32_W, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 16.6.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0400, 0x0B58, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 1.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x0440, 0x0C86, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 2.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x0480, 0x0DB4, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 3.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x04C0, 0x0EE2, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 4.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x0500, 0x1010, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 5.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x0540, 0x113E, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 6.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x0580, 0x126C, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 7.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x05C0, 0x139A, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 8.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x0600, 0x14C8, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 9.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x0640, 0x15F6, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 10.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x0680, 0x1724, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 15.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x06C0, 0x1852, 5, 60, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 16.6.0����ʱ��(��12���ܼ��ַ��ʣ� */
    { 0x0700, 0x1980, 4, 60, fs_attribute(F_U32_W, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 1.2.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0740, 0x1A72, 4, 60, fs_attribute(F_U32_W, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 2.2.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0780, 0x1B64, 4, 60, fs_attribute(F_U32_VAR, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 3.2.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x07C0, 0x1C56, 4, 60, fs_attribute(F_U32_VAR, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 4.2.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0800, 0x1D48, 4, 60, fs_attribute(F_U32_VA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 9.2.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0840, 0x1E3A, 4, 60, fs_attribute(F_U32_VA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 10.2.0ֵ(��12���ܼ��ַ��ʣ� */
    { 0x0900, 0x1F2C, 2, 60, fs_attribute(F_U16_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< �����ܹ�������ƽ��ֵ����12�£� */
};
#include "hfp_def.h"
#include "data_type.h"
#include "fs.h"
#include "list.h"
#include "device.h"
#include "fs_internal.h"
#include "tariff_dlms.h"
#include "lib_fifo.h"
#include "snapshot.h"
#include "dlt645_config.h"

const struct item_t CODE item_char_device_tab[] =
{
    { 0x1001, 0x0000, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_COVER, 1, 0, 1) }, /**< ��ǿ���״̬ */
    { 0x1002, 0x0003, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_TERM, 1, 0, 1) }, /**< ��ť���ϸ�״̬ */
    { 0x1003, 0x0006, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_MAGNETIC, 1, 0, 1) }, /**< �ų�����״̬ */
    { 0x1004, 0x0009, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_MODULE_COVER, 1, 0, 1) }, /**< ģ��ǿ���״̬ */
    { 0x1005, 0x000C, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_PAGE_DOWN, 1, 0, 1) }, /**< δǦ���״̬ */
    { 0x1007, 0x000F, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_S1, 1, 0, 1) }, /**< S1�̽�״̬ */
    { 0x1050, 0x0012, 7, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_RTC, 1, 0, 1) }, /**< ʱ���ļ�ID */
    { 0x1060, 0x001B, 300, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_LIGHT, 1, 0, 1) }, /**< �����ߺ����ļ�ID */
    { 0x1061, 0x0149, 300, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_RS4851, 1, 0, 1) }, /**< RS485-1�ļ�ID */
    { 0x1062, 0x0277, 300, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_GPRS, 1, 0, 1) }, /**< GPRS�ļ�ID */
    { 0x1063, 0x03A5, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_EVEN_OUT, 1, 0, 1) }, /**< �¼��ϱ�evenout */
    { 0x1065, 0x03A8, 300, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_RS4852, 1, 0, 1) }, /**< RS485-2�ļ�ID */
    { 0x1070, 0x04D6, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_BACKLIGHT, 1, 0, 1) }, /**< ���� */
    { 0x1071, 0x04D9, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_ALARM_LED, 1, 0, 1) }, /**< �澯�� A */
    { 0x1072, 0x04DC, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_RED_LED, 1, 0, 1) }, /**< �澯�� B */
    { 0x1073, 0x04DF, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_GREEN_LED, 1, 0, 1) }, /**< �澯�� C */
    { 0x1074, 0x04E2, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_WPLUSE_LED, 1, 0, 1) }, /**< �й��� */
    { 0x1075, 0x04E5, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_VPLUSE_LED, 1, 0, 1) }, /**< �޹��� */
    { 0x1080, 0x04E8, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< �̵��� */
    { 0x1083, 0x04EB, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_BUZZER, 1, 0, 1) }, /**< ������ */
    { 0x1090, 0x04EE, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_KEYBOARD, 1, 0, 1) }, /**< ���� */
};

const struct item_t CODE item_para_calibration_tab[] =
{
    { 0x2001, 0x0000, 8, 1, fs_attribute(F_U16_PARA, notify_05, 0, 1, 0, 1) }, /**< A��У����� */
    { 0x2002, 0x000A, 8, 1, fs_attribute(F_U16_PARA, notify_05, 0, 1, 0, 1) }, /**< B��У����� */
    { 0x2003, 0x0014, 8, 1, fs_attribute(F_U16_PARA, notify_05, 0, 1, 0, 1) }, /**< C��У����� */
    { 0x2004, 0x001E, 20, 1, fs_attribute(F_U16_PARA, notify_05, 0, 1, 0, 1) }, /**< A�����ϵ�� */
    { 0x2005, 0x0034, 20, 1, fs_attribute(F_U16_PARA, notify_05, 0, 1, 0, 1) }, /**< B�����ϵ�� */
    { 0x2006, 0x004A, 20, 1, fs_attribute(F_U16_PARA, notify_05, 0, 1, 0, 1) }, /**< C�����ϵ�� */
    { 0x2007, 0x0060, 20, 1, fs_attribute(F_U16_PARA, notify_05, 0, 1, 0, 1) }, /**< �������Ʋ��� */
    { 0x2008, 0x0076, 8, 1, fs_attribute(F_U16_PARA, notify_05, 0, 1, 0, 1) }, /**< A��B�������ʺ�������ֵ */
    { 0x2009, 0x0080, 20, 1, fs_attribute(F_U32_PARA, notify_05, 0, 1, 0, 1) }, /**< ����У׼����//wjz */
    { 0x200B, 0x0096, 2, 1, fs_attribute(F_S16_PARA, notify_00, 0, 1, 0, 1) }, /**< Ƶ���������� */
    { 0x2010, 0x009A, 1, 1, fs_attribute(F_OCT_PARA, notify_02, 0, 1, 0, 1) }, /**< ����ͨ���л� */
    { 0x2060, 0x009D, 2, 1, fs_attribute(F_U16_PARA, notify_02, 0, 1, 0, 1) }, /**< ���峣�� */
    { 0x2100, 0x00A1, 16, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ���� */
    { 0x2101, 0x00B3, 17, 1, fs_attribute(F_VIS_PARA, notify_09, 0, 1, 0, 1) }, /**< DeviceID1 */
    { 0x2102, 0x00C6, 21, 1, fs_attribute(F_VIS_PARA, notify_00, 0, 1, 0, 1) }, /**< Ӳ���汾�ų���+Ӳ���汾�� */
    { 0x2103, 0x00DD, 23, 1, fs_attribute(F_VIS_PARA, notify_00, 0, 1, 0, 1) }, /**< д������Ϣ */
    { 0x2104, 0x00F6, 11, 1, fs_attribute(F_VIS_PARA, notify_00, 0, 1, 0, 1) }, /**< д����ģ��� */
    { 0x2105, 0x0103, 17, 1, fs_attribute(F_VIS_PARA, notify_00, 0, 1, 0, 1) }, /**< �����ն�У�����ò��� */
    { 0x210C, 0x0116, 25, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< Consumer Identification�ͻ������Ϣ�����������ƣ� */
    { 0x210D, 0x0131, 25, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< Consumer name�ͻ��� */
    { 0x210E, 0x014C, 49, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< Consumer address�ͻ���ַ//wjz */
    { 0x210F, 0x017F, 4, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ���ԱID */
    { 0x2111, 0x0185, 49, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< DeviceID2 */
    { 0x2112, 0x01B8, 13, 1, fs_attribute(F_VIS_PARA, notify_00, 0, 1, 0, 1) }, /**< Serial number of CIU */
    { 0x2118, 0x01C7, 1, 1, fs_attribute(F_U08_PARA, notify_08, 0, 1, 0, 1) }, /**< ��������(��/�����) */
    { 0x2130, 0x01CA, 2, 1, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< ����ģʽ */
    { 0x2132, 0x01CE, 4, 1, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< ��λ��־sign(2)+cnt(2) */
    { 0x2165, 0x01D4, 8, 1, fs_attribute(F_U08_PARA, notify_02, 0, 1, 0, 1) }, /**< ��Ϸ�ʽ�������й���+��+��-��+�޹���+�޹���+�޹��� */
    { 0x2170, 0x01DE, 1, 1, fs_attribute(F_U08_PARA, notify_00, 0, 1, 0, 1) }, /**< ���羲�� */
};

const struct item_t CODE item_para1_tab[] =
{
    { 0x2200, 0x0400, 2, 8, fs_attribute(F_U16_PARA, notify_08, 0, 1, 0, 1) }, /**< CTPT���ӷ�ĸ����ǰ����һ�Σ� */
    { 0x2307, 0x0412, 2, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< security_policy��1��+security_suite��1�� */
    { 0x2322, 0x0416, 9, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< Default Energy Tariff in case of invalid clock */
    { 0x2323, 0x0421, 9, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< Default Max. Demand Tariff in case of invalid clock */
    { 0x2324, 0x042C, 9, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< currently active energy tariff */
    { 0x2325, 0x0437, 9, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< currently active demand tariff */
    { 0x2326, 0x0442, 2, 1, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ʣ���������ʱ�� */
    { 0x251A, 0x0446, 4, 1, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< ��λ���� */
    { 0x2600, 0x044C, 34, 1, fs_attribute(F_ERROR, notify_10, 0, 1, 0, 1) }, /**< ����ʱdst begin -- 8; dst end -- 8;  time_zone -- 2;  deviation -- 1; enable -- 1; clock base -- 1;shift_event_limit -- 1; shift_invalid_limit -- 2; cs -- 2;   clock status ---1 */
    { 0x2601, 0x0470, 1, 1, fs_attribute(F_U08_PARA, notify_10, 0, 1, 0, 1) }, /**<  ����/������  */
    { 0x2D00, 0x0473, 202, 1, fs_attribute(F_OCT_PARA, notify_08, 0, 1, 0, 1) }, /**< GeneralDisplayreadoutList-AutoScroll */
    { 0x2D01, 0x053F, 202, 1, fs_attribute(F_OCT_PARA, notify_08, 0, 1, 0, 1) }, /**< AlternativeDisplayreadoutList-ManualScroll */
    { 0x2D02, 0x060B, 202, 1, fs_attribute(F_OCT_PARA, notify_08, 0, 1, 0, 1) }, /**< AlternativeDisplayreadoutList-ManualScroll//���� */
    { 0x2D03, 0x06D7, 38, 1, fs_attribute(F_OCT_PARA, notify_08, 0, 1, 0, 1) }, /**< Һ�������������������������� */
    { 0x2D21, 0x06FF, 142, 1, fs_attribute(F_OCT_PARA, notify_04, 0, 1, 0, 1) }, /**< DataofBillingPeriod1(Monthly) */
    { 0x2D80, 0x078F, 22, 10, fs_attribute(F_OCT_PARA, notify_04, 0, 1, 0, 1) }, /**< ����\�ն��Ჶ����� */
    { 0x2F00, 0x086D, 4, 1, fs_attribute(F_U32_PARA, notify_08, 0, 1, 0, 1) }, /**< GeneralDisplayreadoutList-AutoScroll */
    { 0x2F01, 0x0873, 4, 1, fs_attribute(F_U32_PARA, notify_08, 0, 1, 0, 1) }, /**< AlternativeDisplayreadoutList-ManualScroll */
    { 0x2F02, 0x0879, 1, 10, fs_attribute(F_U08_PARA, notify_08, 0, 1, 0, 1) }, /**< Dateformat/С��λ��/��λ */
    { 0x2F0C, 0x0885, 3, 1, fs_attribute(F_BIT_PARA, notify_08, 0, 1, 0, 1) }, /**< functionsw1���Ǽ��� */
    { 0x2F0D, 0x088A, 52, 1, fs_attribute(F_OCT_PARA, notify_02, 0, 1, 0, 1) }, /**< ��У�� */
    { 0x2F0E, 0x08C0, 2, 1, fs_attribute(F_U16_PARA, notify_08, 0, 1, 0, 1) }, /**< ������� */
    { 0x2F0F, 0x08C4, 4, 1, fs_attribute(F_U32_PARA, notify_08, 0, 1, 0, 1) }, /**< ������ӳ�xxx��ر�Һ�� */
    { 0x2F80, 0x08CA, 4, 10, fs_attribute(F_OCT_PARA, notify_04, 0, 1, 0, 1) }, /**< ����\�������� */
    { 0x2FF2, 0x08F4, 4, 1, fs_attribute(F_S32_PARA, notify_07, 0, 1, 0, 1) }, /**< Ƶ������PPM */
    { 0x2FF3, 0x08FA, 7, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ƽʱ��ͨ��д����ʱ�� */
};

const struct item_t CODE item_para2_tab[] =
{
    { 0x3001, 0x091E, 2, 1, fs_attribute(F_OCT_PARA, notify_03, 0, 1, 0, 1) }, /**< ��������+������ */
    { 0x3010, 0x0922, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ����ģʽ */
    { 0x3012, 0x0925, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< fraudLockTime */
    { 0x3013, 0x0928, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �ֶ�������λʹ�� */
    { 0x3014, 0x092B, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ������λ��ʽ */
    { 0x3073, 0x092E, 4, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �澯������AlarmFilter1��2 */
    { 0x3075, 0x0938, 1, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ���˸��ɡ��ա��¶�������λͼ��Ϣ */
    { 0x3093, 0x093F, 33, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ˮ���¼���բ��������//wjz */
    { 0x3095, 0x0983, 33, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �¼���¼����//wjz */
    { 0x309A, 0x0A2A, 33, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �¼��ϱ����� */
    { 0x30A0, 0x0AD1, 16, 8, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ��������ͨ��1~8������������ */
    { 0x30B0, 0x0B53, 2, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ���������¼���ȡָ��1~5��ͨ�� */
    { 0x30C0, 0x0B5F, 2, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �������͸��ɲ�������λͼ */
    { 0x30C1, 0x0B63, 7, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ���������ϴ�����ʱ�� */
    { 0x30D0, 0x0B6C, 2, 1, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< �ֶ�������λ�ӳ�ʱ�� */
    { 0x30D1, 0x0B70, 2, 1, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ������ӳ�ʱ�� */
    { 0x30D2, 0x0B74, 2, 1, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ����ť���ӳ�ʱ�� */
    { 0x30D3, 0x0B78, 1, 1, fs_attribute(F_U08_PARA, notify_08, 0, 1, 0, 1) }, /**< ȡ�������ϵ�������˸ */
    { 0x30D4, 0x0B7B, 1, 1, fs_attribute(F_U08_PARA, notify_00, 0, 1, 0, 1) }, /**< �򿪻�ر�Ƶ������˿� */
    { 0x30D5, 0x0B7E, 1, 1, fs_attribute(F_BOOL_PARA, notify_08, 0, 1, 0, 1) }, /**< Һ����λΪ����ʾʹ�� */
    { 0x30D6, 0x0B81, 65, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< GPRSģ��ͬ������ */
    { 0x30D7, 0x0BC4, 65, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< G3ģ��ͬ������ */
    { 0x30D8, 0x0C07, 2, 16, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< Ҫ���͵ĸ������������֧��16�ָ��� */
    { 0x30E8, 0x0C29, 2, 8, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< Ҫ���͵��¼����������֧��8���¼� */
    { 0x30F0, 0x0C3B, 2, 16, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr2, ֻ�洢data_index */
    { 0x3100, 0x0C5D, 35, 6, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr3, =1+33+1��Ŀ�ĵ�ַ���32���ֽ� */
    { 0x3106, 0x0D31, 35, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr3, =1+33+1��Ŀ�ĵ�ַ���32���ֽ� */
    { 0x310B, 0x0DE2, 35, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr3, =1+33+1��Ŀ�ĵ�ַ���32���ֽ� */
    { 0x3110, 0x0E93, 73, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr4, =1+24*3�����֧�����飬ÿ��24���ֽ� */
    { 0x3112, 0x0F27, 73, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr4, =1+24*3�����֧�����飬ÿ��24���ֽ� */
    { 0x3114, 0x0FBB, 73, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr4, =1+24*3�����֧�����飬ÿ��24���ֽ� */
    { 0x3116, 0x104F, 73, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr4, =1+24*3�����֧�����飬ÿ��24���ֽ� */
    { 0x3118, 0x10E3, 73, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr4, =1+24*3�����֧�����飬ÿ��24���ֽ� */
    { 0x311A, 0x1177, 73, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr4, =1+24*3�����֧�����飬ÿ��24���ֽ� */
    { 0x311C, 0x120B, 73, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr4, =1+24*3�����֧�����飬ÿ��24���ֽ� */
    { 0x311E, 0x129F, 73, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr4, =1+24*3�����֧�����飬ÿ��24���ֽ� */
    { 0x3120, 0x1333, 2, 16, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr5 randomisation_start_interval */
    { 0x3130, 0x1355, 1, 16, fs_attribute(F_U08_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr6 number_of_retries */
    { 0x3140, 0x1367, 2, 16, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< log���Ͷ���-IC40-attr7 repetition_delay */
    { 0x3150, 0x1389, 2, 1, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ģ������-�汾�� */
    { 0x3151, 0x138D, 4, 1, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ģ������-block_size */
    { 0x3152, 0x1393, 4, 1, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ģ������-image_size */
    { 0x3153, 0x1399, 1, 1, fs_attribute(F_U08_PARA, notify_00, 0, 1, 0, 1) }, /**< ģ������-����״̬��0-�ɹ�������ֵ-ʧ�� */
    { 0x3154, 0x139C, 2, 1, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ģ����ӳ�ʱ��//wjz */
    { 0x3155, 0x13A0, 2, 1, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< �ų������ӳ�ʱ��//wjz */
};

const struct item_t CODE item_tariff_tab[] =
{
    { 0x3212, 0x13E6, 9, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< calendar_name_active����2 */
    { 0x3213, 0x13F1, 57, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< season_profile_active����3 */
    { 0x3214, 0x142C, 53, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< week_profile_table_active����4 */
    { 0x3215, 0x1463, 209, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< day_profile_table_active����5 */
    { 0x3216, 0x1536, 9, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< calendar_name_passive����6 */
    { 0x3217, 0x1541, 57, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< season_profile_passive����7 */
    { 0x3218, 0x157C, 53, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< week_profile_table_passive����8 */
    { 0x3219, 0x15B3, 209, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< day_profile_table_passive����9 */
    { 0x321A, 0x1686, 6, 1, fs_attribute(F_OCT_PARA, notify_10, 0, 1, 0, 1) }, /**< activate_passive_calendar_time����10 */
    { 0x3232, 0x168E, 701, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< SpecialDaysTable */
    { 0x3235, 0x194D, 61, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< mask_list-Energy */
    { 0x3237, 0x198C, 61, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< mask_list-MaximumDemand */
    { 0x323F, 0x19CB, 28, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< MDIReset(PredefinedScript)/EndofBillingPeriod(ִ��) */
    { 0x3240, 0x19E9, 222, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< TarifficationScriptTable */
    { 0x3241, 0x1AC9, 222, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< PassiveTarifficationScriptTable */
    { 0x3242, 0x1BA9, 106, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< DisconnectercontrolScriptTable */
    { 0x3243, 0x1C15, 184, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< Pushscripttable */
    { 0x3244, 0x1CCF, 60, 1, fs_attribute(F_OCT_PARA, notify_06, 0, 1, 0, 1) }, /**< LimiterScriptTable */
    { 0x3310, 0x1D0D, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�й������������ */
    { 0x3320, 0x1D23, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�й������������ */
    { 0x3330, 0x1D39, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹������������ */
    { 0x3340, 0x1D4F, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹������������ */
    { 0x3350, 0x1D65, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹���I����������� */
    { 0x3360, 0x1D7B, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹���II����������� */
    { 0x3370, 0x1D91, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹���III����������� */
    { 0x3380, 0x1DA7, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹���IV����������� */
    { 0x3390, 0x1DBD, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ��������������� */
    { 0x33A0, 0x1DD3, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ���ڷ���������� */
    { 0x33B0, 0x1DE9, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ����й���������� */
    { 0x33C0, 0x1DFF, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�����й���������� */
    { 0x3410, 0x1E15, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�й����������������ʱ�� */
    { 0x3420, 0x1E30, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�й����������������ʱ�� */
    { 0x3430, 0x1E4B, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹����������������ʱ�� */
    { 0x3440, 0x1E66, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹����������������ʱ�� */
    { 0x3450, 0x1E81, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹���I���������������ʱ�� */
    { 0x3460, 0x1E9C, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹���II���������������ʱ�� */
    { 0x3470, 0x1EB7, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹���III���������������ʱ�� */
    { 0x3480, 0x1ED2, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�޹���IV���������������ʱ�� */
    { 0x3490, 0x1EED, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�������������������ʱ�� */
    { 0x34A0, 0x1F08, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ���ڷ��������������ʱ�� */
    { 0x34B0, 0x1F23, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ����й��������������ʱ�� */
    { 0x34C0, 0x1F3E, 5, 5, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< �ֶ���λ�����й��������������ʱ�� */
    { 0x34C0, 0x1F59, 37, 6, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log����ʱ��-ic22�����֧��12��ʱ�䣬ʱ���ʽΪ����ʱ�֣�=1+3*12(����) */
    { 0x34C6, 0x2039, 37, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log����ʱ��-ic22�����֧��12��ʱ�䣬ʱ���ʽΪ����ʱ�֣�=1+3*12(����) */
    { 0x34CB, 0x20F4, 37, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< log����ʱ��-ic22�����֧��12��ʱ�䣬ʱ���ʽΪ����ʱ�֣�=1+3*12(����) */
};

const struct item_t CODE item_history_tab[] =
{
    { 0x3500, 0x0000, 4, 60, fs_attribute(F_U32_WH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 1.8.0(��12���ܼ��ַ��ʣ� */
    { 0x3540, 0x00F2, 4, 60, fs_attribute(F_U32_WH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 2.8.0(��12���ܼ��ַ��ʣ� */
    { 0x3580, 0x01E4, 4, 60, fs_attribute(F_U32_WH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 5.8.0(��12���ܼ��ַ��ʣ� */
    { 0x35C0, 0x02D6, 4, 60, fs_attribute(F_U32_VARH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 6.8.0(��12���ܼ��ַ��ʣ� */
    { 0x3600, 0x03C8, 4, 60, fs_attribute(F_U32_VARH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 7.8.0(��12���ܼ��ַ��ʣ� */
    { 0x3640, 0x04BA, 4, 60, fs_attribute(F_U32_VARH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 8.8.0(��12���ܼ��ַ��ʣ� */
    { 0x3680, 0x05AC, 4, 60, fs_attribute(F_U32_VAH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 9.8.0(��12���ܼ��ַ��ʣ� */
    { 0x36C0, 0x069E, 4, 60, fs_attribute(F_U32_VAH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 10.8.0(��12���ܼ��ַ��ʣ� */
    { 0x3700, 0x0790, 4, 60, fs_attribute(F_U32_WH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 15.8.0(��12���ܼ��ַ��ʣ� */
    { 0x3740, 0x0882, 4, 60, fs_attribute(F_U32_WH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 16.8.0(��12���ܼ��ַ��ʣ� */
    { 0x3780, 0x0974, 4, 60, fs_attribute(F_U32_VARH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 3.8.0(��12���ܼ��ַ��ʣ� */
    { 0x37C0, 0x0A66, 4, 60, fs_attribute(F_U32_VARH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 4.8.0(��12���ܼ��ַ��ʣ� */
    { 0x3800, 0x0B58, 4, 60, fs_attribute(F_U32_VARH, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< 130.8.0(��12���ܼ��ַ��ʣ� */
};

const struct item_t CODE item_comm_tab[] =
{
    { 0x4000, 0x22E6, 13, 3, fs_attribute(F_OCT_PARA, notify_12, 0, 1, 0, 1) }, /**< IECHDLCsetup-HDLCOpticalport */
    { 0x4007, 0x230F, 8, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< Mng/Preclientsys_title */
    { 0x4008, 0x2319, 17, 3, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< Master��Կmk */
    { 0x4011, 0x234E, 9, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< LLS���� */
    { 0x4018, 0x2359, 17, 3, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< (Clock Client) mk */
    { 0x401B, 0x238E, 17, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< HLS���� */
    { 0x401C, 0x23A1, 16, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< Dedicatedkey��ʱ�Ự��Կ */
    { 0x4028, 0x23B3, 17, 3, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< (Reading Client)mk */
    { 0x4033, 0x23E8, 1, 1, fs_attribute(F_U8_second, notify_00, 0, 1, 0, 1) }, /**< ClockTimeShiftLimit */
    { 0x4100, 0x23EB, 16, 6, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �ͻ���+���������� */
    { 0x4325, 0x244D, 5, 1, fs_attribute(F_OCT_PARA, notify_09, 0, 1, 0, 1) }, /**< GPRSKeepAliveTimeInterval */
    { 0x4326, 0x2454, 4, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< LocalAuthenticationprotection */
    { 0x4400, 0x245A, 2, 2, fs_attribute(F_OCT_PARA, notify_09, 0, 1, 0, 1) }, /**< ��վ1�����˿ں�(2)+������վ�����˿ں�(2) */
    { 0x4403, 0x2460, 4, 2, fs_attribute(F_OCT_PARA, notify_09, 0, 1, 0, 1) }, /**< ��վ1IP��ַ(4)+������վIP��ַ(4) */
    { 0x4405, 0x246A, 17, 3, fs_attribute(F_OCT_PARA, notify_09, 0, 1, 0, 1) }, /**< д��վSMS��(17)+������վSMS��(17)+��������SMS��(17) */
    { 0x4408, 0x249F, 33, 4, fs_attribute(F_OCT_PARA, notify_09, 0, 1, 0, 1) }, /**< APN(33)+����APN(33)+PDP�û���(33)+PDP�û�����(33) */
    { 0x440C, 0x2525, 3, 1, fs_attribute(F_OCT_PARA, notify_09, 0, 1, 0, 1) }, /**< GPRSģʽ��(3) */
    { 0x440D, 0x252A, 9, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< SMS��ϢwriteTextmessageforSMS+PIN������ */
    { 0x440F, 0x253E, 6, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ����ʱ��� */
    { 0x4417, 0x2546, 1, 2, fs_attribute(F_OCT_PARA, notify_09, 0, 1, 0, 1) }, /**< PPP������֤��ʽ��������ģʽ������ͨ�Ŷ���ʱ��///ywq */
    { 0x4420, 0x254A, 2, 1, fs_attribute(F_OCT_PARA, notify_09, 0, 1, 0, 1) }, /**< ������ģʽ����TCP�˿�//ywq */
    { 0x45B1, 0x254E, 4, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �澯���� */
    { 0x4600, 0x2554, 187, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ImageTransfer */
    { 0x4601, 0x2611, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ģ��������־ */
    { 0x4614, 0x2614, 15, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ImageTransferActivationScheduler */
    { 0x4700, 0x2625, 7, 32, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �¼���һ�η���ʱ��//wjz */
    { 0x4720, 0x2707, 7, 32, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �¼���һ�η���ʱ�� */
    { 0x4740, 0x27E9, 7, 32, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �¼���һ�η���ʱ�� */
    { 0x4761, 0x28CB, 7, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ������λ�¼���һ�η���ʱ��\\JB */
    { 0x4780, 0x28D4, 2, 96, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< �¼���������//wjz */
    { 0x47E0, 0x2996, 2, 32, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< C���¼���������//wjz */
    { 0x4800, 0x29D8, 4, 32, fs_attribute(F_U32_SEC, notify_00, 0, 1, 0, 1) }, /**< �¼���������ʱ��//wjz */
    { 0x4820, 0x2A5A, 4, 32, fs_attribute(F_U32_SEC, notify_00, 0, 1, 0, 1) }, /**< �¼���������ʱ�� */
    { 0x4840, 0x2ADC, 4, 32, fs_attribute(F_U32_SEC, notify_00, 0, 1, 0, 1) }, /**< �¼���������ʱ�� */
    { 0x4860, 0x2B5E, 7, 32, fs_attribute(F_OCT_PARA, notify_04, 0, 1, 0, 1) }, /**< �¼���һ�ν���ʱ��//wjz */
    { 0x4880, 0x2C40, 7, 32, fs_attribute(F_OCT_PARA, notify_04, 0, 1, 0, 1) }, /**< �¼���һ�ν���ʱ�� */
    { 0x48A0, 0x2D22, 7, 32, fs_attribute(F_OCT_PARA, notify_04, 0, 1, 0, 1) }, /**< �¼���һ�ν���ʱ�� */
    { 0x4900, 0x2E04, 1, 7, fs_attribute(F_ENUM_PARA, notify_00, 0, 1, 0, 1) }, /**< �¼����룬���߼��󶨣������޸�(��׼+�Ե�+�̵���+����+ͨ��+MBUS+pakistan) */
    { 0x4B01, 0x2E0D, 7, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< EndofBillingPeriod1(Monthly) */
    { 0x4B02, 0x2E16, 7, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< last_time */
    { 0x4B04, 0x2E26, 9, 2, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �ն���ʱ��///ywq */
    { 0x4B10, 0x2E3A, 1, 2, fs_attribute(F_ENUM_PARA, notify_12, 0, 1, 0, 1) }, /**< IEC����ͨ�ſ����� */
    { 0x4B11, 0x2E3E, 1, 2, fs_attribute(F_ENUM_PARA, notify_12, 0, 1, 0, 1) }, /**< RS485����ͨ�ſ�����//wjz */
    { 0x4B20, 0x2E42, 82, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ������¼�ת��ÿ���¼�8���ֽڣ�time+code����ǰ�����ֽ��ǣ�num+ptr) */
    { 0x4B21, 0x2E96, 4, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �¼���ȡ��־�Ĵ���Unread_Log_Files_Status_Register */
    { 0x4B30, 0x2E9C, 4, 13, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ����ͨ���ϴη���ʱ�� */
    { 0x4B40, 0x2ED2, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ����ε�ص��¼� */
    { 0x4B50, 0x2ED5, 3, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< 485ͨ�ŵ�ַ */
    { 0x4B51, 0x2EDA, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, 0, 1, 0, 1) }, /**< ע��״̬ */
    { 0x4D00, 0x2EDD, 98, 2, fs_attribute(F_OCT_PARA, notify_06, 0, 1, 0, 1) }, /**< �̵���������ֵ�� ���� + ���� */
    { 0x4D02, 0x2FA3, 10, 1, fs_attribute(F_OCT_PARA, notify_06, 0, 1, 0, 1) }, /**< �̵�������������������Number of Reclosing_Norm(1) + Middle Timeout/Norm(2) + Final state_Norm(1) + Number of Reclosing_Emg(1) + Middle Timeout/Emg2) + Final state_Emg(1) + End Timeout(minutes)(2) */
    { 0x4D03, 0x2FAF, 31, 1, fs_attribute(F_OCT_PARA, notify_06, 0, 1, 0, 1) }, /**< �̵������ز�������monitored_value(2) + min_over_threshold_duration(4)+min_under_threshold_duration(4)+emergency_profile_id(1)+emergency_activation_time(7)+emergency_duration(4)+emergency_profile_group_id_list(1)+ normal_threshold(4) + emergency_threshold(4) */
    { 0x4D04, 0x2FD0, 1, 1, fs_attribute(F_ENUM_PARA, notify_06, 0, 1, 0, 1) }, /**< �̵�������ģʽ��0-4�� */
    { 0x4D05, 0x2FD3, 9, 2, fs_attribute(F_OCT_PARA, notify_06, 0, 1, 0, 1) }, /**< �̵�����ʱ���� + �̵�����ʱ��ֵ���� */
    { 0x4D07, 0x2FE7, 74, 1, fs_attribute(F_OCT_PARA, notify_06, 0, 1, 0, 1) }, /**< ���ɿ�������բʹ��ʱ��� */
    { 0x4D10, 0x3033, 33, 1, fs_attribute(F_OCT_PARA, notify_09, 0, 1, 0, 1) }, /**< �α�����վSMS�� */
    { 0x4D20, 0x3056, 1, 1, fs_attribute(F_U08_PARA, notify_12, 0, 1, 0, 1) }, /**< CTPTʹ��λ */
    { 0x4D30, 0x3059, 2, 1, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< �޸�CTPT���� */
    { 0x4D31, 0x305D, 6, 1, fs_attribute(F_OCT_PARA, notify_08, 0, 1, 0, 0) }, /**< Token����봦���� */
    { 0x4D40, 0x3063, 200, 1, fs_attribute(F_OCT_PARA, notify_08, 0, 1, 0, 1) }, /**< �ⲿ�ڷ���ģ������֡����ʹ�� */
    { 0x4D41, 0x312D, 200, 1, fs_attribute(F_OCT_PARA, notify_08, 0, 1, 0, 1) }, /**< ģ��Ӧ���ⲿ�ڷ���֡����ʹ�� */
    { 0x4D42, 0x31F7, 12, 1, fs_attribute(F_OCT_PARA, notify_08, 0, 1, 0, 1) }, /**< Pushsetup-OnConnectivityģ���¼�����б�ǰ��2���ֽڱ�ʾ������� */
    { 0x4D50, 0x3205, 1, 1, fs_attribute(F_ENUM_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ���ڣ������ﶬ//JB */
};

const struct item_t CODE item_RamMap_tab[] =
{
    { 0x5010, 0x3222, 2, 9, fs_attribute(F_V_event, notify_00, 0, 1, 0, 1) }, /**< MagnitudeofUnderVoltage(sag)inphaseL1 */
    { 0x5A00, 0x3236, 7, 13, fs_attribute(F_U16_second, notify_00, 0, 1, 0, 1) }, /**< ����ͨ��1�ϴη���ʱ�� */
    { 0x5B00, 0x3293, 2, 32, fs_attribute(F_U16_second, notify_04, 0, 1, 0, 1) }, /**< Timethreshold//wjz */
    { 0x5C00, 0x32D5, 2, 1, fs_attribute(F_U16_V, notify_04, 0, 1, 0, 1) }, /**< Ƿѹ��ֵ��Uuv�� */
    { 0x5C01, 0x32D9, 2, 1, fs_attribute(F_U16_V, notify_04, 0, 1, 0, 1) }, /**< ��ѹ��ֵ��Uov�� */
    { 0x5C02, 0x32DD, 2, 1, fs_attribute(F_U16_V, notify_04, 0, 1, 0, 1) }, /**< ʧѹ�ٽ緧ֵ��Ulv�� */
    { 0x5C03, 0x32E1, 2, 1, fs_attribute(F_U16_V, notify_04, 0, 1, 0, 1) }, /**< �����ѹ��Upf�� */
    { 0x5C04, 0x32E5, 2, 1, fs_attribute(F_A_event, notify_04, 0, 1, 0, 1) }, /**< ������ֵI_Limit(unit 1A�� */
    { 0x5C05, 0x32E9, 2, 1, fs_attribute(F_Percent, notify_04, 0, 1, 0, 1) }, /**< ��ѹ��ƽ����(0.0%) */
    { 0x5C06, 0x32ED, 2, 1, fs_attribute(F_U16_V, notify_04, 0, 1, 0, 1) }, /**< ���Ƿѹ��ֵVlow(Vlow) */
    { 0x5C07, 0x32F1, 4, 1, fs_attribute(F_U32_W, notify_04, 0, 1, 0, 1) }, /**< �������޷�ֵ��MD_Limit�� */
    { 0x5C08, 0x32F7, 2, 1, fs_attribute(F_Percent, notify_04, 0, 1, 0, 1) }, /**< ������ƽ����(0.0%) */
    { 0x5C09, 0x32FB, 2, 1, fs_attribute(F_U16_V, notify_04, 0, 1, 0, 1) }, /**< ʧѹ�ָ���ֵ��Ulvr�� */
    { 0x5C0A, 0x32FF, 2, 1, fs_attribute(F_Percent, notify_04, 0, 1, 0, 1) }, /**< ��·���������ֵXbp(0.0%) */
    { 0x5C0B, 0x3303, 2, 1, fs_attribute(F_U16_A, notify_04, 0, 1, 0, 1) }, /**< ���������Ipf�� */
    { 0x5C0C, 0x3307, 2, 1, fs_attribute(F_Percent, notify_04, 0, 1, 0, 1) }, /**< ��ѹTHD���޷�ֵ(0.0%) */
    { 0x5C0D, 0x330B, 2, 1, fs_attribute(F_Percent, notify_04, 0, 1, 0, 1) }, /**< ����THD���޷�ֵ(0.0%) */
    { 0x5C0E, 0x330F, 2, 1, fs_attribute(F_U16_A, notify_04, 0, 1, 0, 1) }, /**< ��������ֵ */
    { 0x5C0F, 0x3313, 2, 1, fs_attribute(F_U16_Hz, notify_04, 0, 1, 0, 1) }, /**< Ƶ�ʹ��߷�ֵ��Fn_H�� */
    { 0x5C10, 0x3317, 2, 1, fs_attribute(F_U16_Pf, notify_04, 0, 1, 0, 1) }, /**< �͹���������ֵPF_Limit */
    { 0x5C11, 0x331B, 2, 1, fs_attribute(F_U16_V, notify_04, 0, 1, 0, 1) }, /**< ʧ����ѹ�������ޣ�Ulc�� */
    { 0x5C12, 0x331F, 2, 1, fs_attribute(F_U16_A, notify_04, 0, 1, 0, 1) }, /**< ʧ�������������ޣ�Ilc�� */
    { 0x5C13, 0x3323, 2, 1, fs_attribute(F_U16_A, notify_04, 0, 1, 0, 1) }, /**< ʧ���ָ�������Ilcr�� */
    { 0x5C14, 0x3327, 2, 1, fs_attribute(F_Percent, notify_04, 0, 1, 0, 1) }, /**< ���ʲ�ƽ����(0.0%) */
    { 0x5C15, 0x332B, 4, 1, fs_attribute(F_U32_W, notify_04, 0, 1, 0, 1) }, /**< ���ع��ʷ�ֵ��P_Limit�� */
    { 0x5C16, 0x3331, 2, 1, fs_attribute(F_U16_Hz, notify_04, 0, 1, 0, 1) }, /**< Ƶ�ʹ��ͷ�ֵ��Fn_L�� */
    { 0x5C17, 0x3335, 4, 1, fs_attribute(F_U32_W, notify_04, 0, 1, 0, 1) }, /**< ��������ֵ(kW) */
    { 0x5C18, 0x333B, 2, 1, fs_attribute(F_U16_V, notify_04, 0, 1, 0, 1) }, /**< ȱ���߼���� */
    { 0x5C19, 0x333F, 2, 1, fs_attribute(F_U16_Ang, notify_04, 0, 1, 0, 1) }, /**< ȱ���ߵ�ѹ��Ƿ�ֵ */
    { 0x5C1A, 0x3343, 2, 1, fs_attribute(F_U16_V, notify_04, 0, 1, 0, 1) }, /**< ��ص�ѹ���޷�ֵ(Vhigh)//wjz */
    { 0x5C1B, 0x3347, 4, 1, fs_attribute(F_U32_W, notify_04, 0, 1, 0, 1) }, /**< ���ܷ����ʷ�ֵ(kW)//wjz */
    { 0x5D00, 0x334D, 4, 7, fs_attribute(F_FLOAT32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ����6����ʷCT��� */
    { 0x5D10, 0x336B, 4, 7, fs_attribute(F_FLOAT32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ����6����ʷPT��� */
    { 0x5D20, 0x3389, 2, 1, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< EEPROM�Լ��� */
};

const struct item_t CODE item_disp_tab[] =
{
    { 0x6001, 0x0000, 4, 2, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< currentAverageActiveenergyimport/export */
    { 0x6003, 0x000A, 4, 2, fs_attribute(F_U32_VAR, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< currentAveragereactiveenergyimport/export */
    { 0x6005, 0x0014, 4, 1, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< currentAverageActiveenergyCombinedtotal(|+A|+|-A|) */
    { 0x6006, 0x001A, 4, 3, fs_attribute(F_U32_A, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< currentAverageSlidingAveragecurrentL1/L2/L3(forfusesupervision) */
    { 0x6009, 0x0028, 4, 2, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< currentAverageAverageImportPower(+A)/AverageNetPower(|+A|-|-A|)/AverageTotalPower(|+A|+|-A|) */
    { 0x600B, 0x0032, 4, 1, fs_attribute(F_U32_W_SIGN, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< currentAverageNetPower(|+A|-|-A|) */
    { 0x6101, 0x0038, 4, 2, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< LastActiveenergyimport/export */
    { 0x6103, 0x0042, 4, 2, fs_attribute(F_U32_VAR, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< Lastreactiveenergyimport/export */
    { 0x6105, 0x004C, 4, 1, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< LastActiveenergyCombinedtotal(|+A|+|-A|) */
    { 0x6106, 0x0052, 4, 3, fs_attribute(F_U32_A, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< LastSlidingAveragecurrentL1/L2/L3(forfusesupervision) */
    { 0x6109, 0x0060, 4, 2, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< LastAverageImportPower(+A)/AverageNetPower(|+A|-|-A|)/AverageTotalPower(|+A|+|-A|) */
    { 0x610B, 0x006A, 4, 1, fs_attribute(F_U32_W_SIGN, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< LastAverageNetPower(|+A|-|-A|) */
    { 0x610C, 0x0070, 1, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ��7��ʾ�б�����2ͳһ�ظ�����д��δʵ�� */
    { 0x610D, 0x0073, 4, 1, fs_attribute(F_U32_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ��7����4˲ʱ��+˲ʱ����+�����ն���+�¼����ڹ̶���0 */
    { 0x610E, 0x0079, 1, 1, fs_attribute(F_U32_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ���ʼ�������IDֻ������֪ͨ */
    { 0x6200, 0x007C, 4, 16, fs_attribute(F_U32_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ��4M_BUS����ID����д�̶��ظ� */
    { 0x6F10, 0x00BE, 1, 3, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< Һ��A\B\C��ָʾ */
    { 0x6F20, 0x00C3, 1, 3, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< Һ��A\B\C��ָʾ��������ָʾ */
    { 0x6F30, 0x00C8, 1, 3, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< Һ��A\B\C��ָʾ����ָʾ */
    { 0x6F40, 0x00CD, 1, 3, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< Һ��A\B\C��ָʾ����ָʾ */
    { 0x6F50, 0x00D2, 1, 3, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ABC�෴�����¼� */
    { 0x6F60, 0x00D7, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_TARIFF, 1, 0, 1) }, /**< ����T״̬(��ʾ�����ʶ����״̬) */
    { 0x6F61, 0x00DA, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_TARIFF, 1, 0, 1) }, /**< ���ʱ��(���ʺ�1��8) */
    { 0x6F62, 0x00DD, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< L1��ѹʧѹ��˸��־ */
    { 0x6F63, 0x00E0, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< L2��ѹʧѹ��˸��־ */
    { 0x6F64, 0x00E3, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< L3��ѹʧѹ��˸��־ */
    { 0x6F67, 0x00E6, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< L1���ᷴ����������˸��־ */
    { 0x6F68, 0x00E9, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< L2���ᷴ����������˸��־ */
    { 0x6F69, 0x00EC, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< L3���ᷴ����������˸��־ */
    { 0x6F6A, 0x00EF, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_LCD, 1, 0, 1) }, /**< ��ʾ��Ц����־״̬ */
    { 0x6F70, 0x00F2, 1, 1, fs_attribute(F_ENUM_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ���¼��Ĳ������ */
    { 0x6F82, 0x00F5, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_COMM, 1, 0, 1) }, /**< Һ��ͨѶ���� */
    { 0x6F90, 0x00F8, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_LCD, 1, 0, 1) }, /**< Һ��������s1 */
    { 0x6F91, 0x00FB, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_LCD, 1, 0, 1) }, /**< Һ��������s2 */
    { 0x6F92, 0x00FE, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_LCD, 1, 0, 1) }, /**< Һ��������s3 */
    { 0x6F93, 0x0101, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< Һ��������s4 */
    { 0x6F94, 0x0104, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< Һ��������s5 */
    { 0x6F95, 0x0107, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< Һ��������s6 */
    { 0x6F96, 0x010A, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< Һ��������s7 */
    { 0x6F97, 0x010D, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< Һ��������s8 */
    { 0x6F98, 0x0110, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< Һ��������s9 */
    { 0x6FA0, 0x0113, 2, 3, fs_attribute(F_U16_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʾ��ABC�������ʵʱ������־����������ѹ��Ƿѹ��ʧѹ�����ࣩ */
    { 0x6FA3, 0x011B, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< �ܹ��ʷ��� */
    { 0x6FA4, 0x011E, 1, 2, fs_attribute(F_U08_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��· + ȱ���ߣ�����ʱ�� */
    { 0x6FA5, 0x0122, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_LCD, 1, 0, 1) }, /**< ����1��������ʾ������ָʾ���ã� */
    { 0x6FA6, 0x0125, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_LCD, 1, 0, 1) }, /**< ����2��������ʾ������ָʾ���ã� */
    { 0x6FA7, 0x0128, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< �����е磨������ʾ������ָʾ���ã� */
    { 0x6FA8, 0x012B, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʷ����ǣ�������ʾ������ָʾ���ã� */
    { 0x6FA9, 0x012E, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʷ���˸ǣ�������ʾ������ָʾ���ã� */
    { 0x6FAA, 0x0131, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʷ��ģ��ǣ�������ʾ������ָʾ���ã� */
    { 0x6FAB, 0x0134, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʷǿ�ų���������ʾ������ָʾ���ã� */
    { 0x6FAC, 0x0137, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ǰU����������ʱ����������ʾ������ָʾ���ã� */
    { 0x6FAD, 0x013A, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʷU������������ʾ������ָʾ���ã� */
    { 0x6FAE, 0x013D, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_DST, 1, 0, 1) }, /**< ��ǰ����ʱ��������ʾ������ָʾ���ã� */
    { 0x6FAF, 0x0140, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< ��ǰ֧���ֶ���բ��������ʾ������ָʾ���ã� */
    { 0x6FB0, 0x0143, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< δ��̱�������ʾ������ָʾ���ã� */
    { 0x6FB1, 0x0146, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_LCD, 1, 0, 1) }, /**< ����ģʽ��������ʾ������ָʾ���ã� */
    { 0x6FB2, 0x0149, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ǰ��·������ʱ����������ʾ������ָʾ���ã� */
    { 0x6FB3, 0x014C, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ˲ʱU����������ʱ�� */
    { 0x6FB4, 0x014F, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʷ��·��������ʾ������ָʾ���ã� */
    { 0x6FB5, 0x0152, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ǰ���أ�������ʾ������ָʾ���ã� */
    { 0x6FB6, 0x0155, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʷ���أ�������ʾ������ָʾ���ã� */
    { 0x6FB7, 0x0158, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ǰ�������ޣ�������ʾ������ָʾ���ã� */
    { 0x6FB8, 0x015B, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʷ�������ޣ�������ʾ������ָʾ���ã� */
    { 0x6FB9, 0x015E, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ǰ�̵������ϣ�������ʾ������ָʾ���ã� */
    { 0x6FBA, 0x0161, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʷ�̵������ϣ�������ʾ������ָʾ���ã� */
    { 0x6FBB, 0x0164, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< ��ʷʱ����Ч��������ʾ������ָʾ���ã� */
    { 0x6FBC, 0x0167, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< ��ʷ�ϵ������У�����������ʾ������ָʾ���ã� */
    { 0x6FBD, 0x016A, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< ��ʷ����ϵͳ���ֹ��ϣ�������ʾ������ָʾ���ã� */
    { 0x6FBE, 0x016D, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ǰFRAMӲ�����ϣ�������ʾ������ָʾ���ã� */
    { 0x6FBF, 0x0170, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʷFRAMӲ�����ϣ�������ʾ������ָʾ���ã� */
    { 0x6FC0, 0x0173, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ǰDATA FLASHӲ�����ϣ�������ʾ������ָʾ���ã� */
    { 0x6FC1, 0x0176, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��ʷDATA FLASHӲ�����ϣ�������ʾ������ָʾ���ã� */
    { 0x6FC2, 0x0179, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< ��ʷ�쳣��λ��������ʾ������ָʾ���ã� */
    { 0x6FC3, 0x017C, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< �ܹ��ʻ��� */
    { 0x6FC4, 0x017F, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< A�������������ʾ������ָʾ���ã� */
    { 0x6FC5, 0x0182, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< B�������������ʾ������ָʾ���ã� */
    { 0x6FC6, 0x0185, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< C�������������ʾ������ָʾ���ã� */
    { 0x6FC7, 0x0188, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< ����Ǽ��ʹ�ܣ�������ʾ������ָʾ���ã� */
    { 0x6FD3, 0x018B, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ActiveQuadrant */
    { 0x6FD4, 0x018E, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< ʮ�ּ� */
    { 0x6FD5, 0x0191, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< L1����״̬ */
    { 0x6FD6, 0x0194, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< L2����״̬ */
    { 0x6FD7, 0x0197, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< L3����״̬ */
    { 0x6FE3, 0x019A, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< Һ�����Ƿѹ */
    { 0x6FE5, 0x019D, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰ����ͨ�� */
};

const struct item_t CODE item_demandram_tab[] =
{
    { 0x7010, 0x0000, 4, 5, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(+) */
    { 0x7020, 0x0016, 4, 5, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(-) */
    { 0x7030, 0x002C, 4, 5, fs_attribute(F_U32_VAR, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(+) */
    { 0x7040, 0x0042, 4, 5, fs_attribute(F_U32_VAR, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(-) */
    { 0x7050, 0x0058, 4, 5, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QI) */
    { 0x7060, 0x006E, 4, 5, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QII) */
    { 0x7070, 0x0084, 4, 5, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QIII) */
    { 0x7080, 0x009A, 4, 5, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QIV) */
    { 0x7090, 0x00B0, 4, 5, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ApparentMD(+) */
    { 0x70A0, 0x00C6, 4, 5, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ApparentMD(-) */
    { 0x70B0, 0x00DC, 4, 5, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(|QI+QIV|+|QII+QIII|) */
    { 0x70C0, 0x00F2, 4, 5, fs_attribute(F_U32_W, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(|QI+QIV|-|QII+QIII|) */
    { 0x7110, 0x0108, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(+)time */
    { 0x7120, 0x0123, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(-)time */
    { 0x7130, 0x013E, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(+)time */
    { 0x7140, 0x0159, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(-)time */
    { 0x7150, 0x0174, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QI)time */
    { 0x7160, 0x018F, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QII)time */
    { 0x7170, 0x01AA, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QIII)time */
    { 0x7180, 0x01C5, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QIV)time */
    { 0x7190, 0x01E0, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ApparentMD(+)time */
    { 0x71A0, 0x01FB, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ApparentMD(-)time */
    { 0x71B0, 0x0216, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(|QI+QIV|+|QII+QIII|)time */
    { 0x71C0, 0x0231, 5, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(|QI+QIV|-|QII+QIII|)time */
    { 0x7210, 0x024C, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(+)value+time */
    { 0x7220, 0x027B, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(-)value+time */
    { 0x7230, 0x02AA, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(+)value+time */
    { 0x7240, 0x02D9, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(-)value+time */
    { 0x7250, 0x0308, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QI)value+time */
    { 0x7260, 0x0337, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QII)value+time */
    { 0x7270, 0x0366, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QIII)value+time */
    { 0x7280, 0x0395, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ReactiveMD(QIV)value+time */
    { 0x7290, 0x03C4, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ApparentMD(+)value+time */
    { 0x72A0, 0x03F3, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ApparentMD(-)value+time */
    { 0x72B0, 0x0422, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(|QI+QIV|+|QII+QIII|)value+time */
    { 0x72C0, 0x0451, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< ActiveMD(|QI+QIV|-|QII+QIII|)value+time */
    { 0x7310, 0x0480, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handActiveMD(+)value+time */
    { 0x7320, 0x04AF, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handActiveMD(-)value+time */
    { 0x7330, 0x04DE, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handReactiveMD(+)value+time */
    { 0x7340, 0x050D, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handReactiveMD(-)value+time */
    { 0x7350, 0x053C, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handReactiveMD(QI)value+time */
    { 0x7360, 0x056B, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handReactiveMD(QII)value+time */
    { 0x7370, 0x059A, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handReactiveMD(QIII)value+time */
    { 0x7380, 0x05C9, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handReactiveMD(QIV)value+time */
    { 0x7390, 0x05F8, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handApparentMD(+)value+time */
    { 0x73A0, 0x0627, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handApparentMD(-)value+time */
    { 0x73B0, 0x0656, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handActiveMD(|QI+QIV|+|QII+QIII|)value+time */
    { 0x73C0, 0x0685, 9, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DEMAND, 1, 0, 1) }, /**< handActiveMD(|QI+QIV|-|QII+QIII|)value+time */
};

const struct item_t CODE item_energy_powoff_save_tab[] =
{
    { 0x8000, 0x33A2, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������й���������+ */
    { 0x8010, 0x33AE, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������й���������- */
    { 0x8020, 0x33BA, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������޹���������1 */
    { 0x8030, 0x33C6, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������޹���������2 */
    { 0x8040, 0x33D2, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������޹���������3 */
    { 0x8050, 0x33DE, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������޹���������4 */
    { 0x8080, 0x33EA, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA��������������� */
    { 0x8090, 0x33F6, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������������巴 */
    { 0x8100, 0x3402, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������й���������+ */
    { 0x8110, 0x340E, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������й���������- */
    { 0x8120, 0x341A, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������޹���������1 */
    { 0x8130, 0x3426, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������޹���������2 */
    { 0x8140, 0x3432, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������޹���������3 */
    { 0x8150, 0x343E, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������޹���������4 */
    { 0x8180, 0x344A, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB��������������� */
    { 0x8190, 0x3456, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������������巴 */
    { 0x8200, 0x3462, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������й���������+ */
    { 0x8210, 0x346E, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������й���������- */
    { 0x8220, 0x347A, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������޹���������1 */
    { 0x8230, 0x3486, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������޹���������2 */
    { 0x8240, 0x3492, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������޹���������3 */
    { 0x8250, 0x349E, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������޹���������4 */
    { 0x8280, 0x34AA, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC��������������� */
    { 0x8290, 0x34B6, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������������巴 */
    { 0x8300, 0x34C2, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������й���������+ */
    { 0x8310, 0x34CE, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������й���������- */
    { 0x8320, 0x34DA, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������޹���������1 */
    { 0x8330, 0x34E6, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������޹���������2 */
    { 0x8340, 0x34F2, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������޹���������3 */
    { 0x8350, 0x34FE, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������޹���������4 */
    { 0x8380, 0x350A, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������������� */
    { 0x8390, 0x3516, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�����������巴 */
    { 0x8400, 0x3522, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< �¶��й������� */
    { 0x8410, 0x352E, 2, 5, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< �¶��й����巴 */
};

const struct item_t CODE item_energySave_tab[] =
{
    { 0x8800, 0x3722, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< �¶��й������� */
    { 0x8810, 0x3738, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< �¶��й����ܷ� */
    { 0x8C00, 0x374E, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������й�����+ */
    { 0x8C10, 0x3764, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������й�����- */
    { 0x8C20, 0x377A, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������޹�����1 */
    { 0x8C30, 0x3790, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������޹�����2 */
    { 0x8C40, 0x37A6, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������޹�����3 */
    { 0x8C50, 0x37BC, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA������޹�����4 */
    { 0x8C80, 0x37D2, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA��������ڵ����� */
    { 0x8C90, 0x37E8, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰA��������ڵ��ܷ� */
    { 0x8D00, 0x37FE, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������й�����+ */
    { 0x8D10, 0x3814, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������й�����- */
    { 0x8D20, 0x382A, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������޹�����1 */
    { 0x8D30, 0x3840, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������޹�����2 */
    { 0x8D40, 0x3856, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������޹�����3 */
    { 0x8D50, 0x386C, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB������޹�����4 */
    { 0x8D80, 0x3882, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB��������ڵ����� */
    { 0x8D90, 0x3898, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰB��������ڵ��ܷ� */
    { 0x8E00, 0x38AE, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������й�����+ */
    { 0x8E10, 0x38C4, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������й�����- */
    { 0x8E20, 0x38DA, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������޹�����1 */
    { 0x8E30, 0x38F0, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������޹�����2 */
    { 0x8E40, 0x3906, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������޹�����3 */
    { 0x8E50, 0x391C, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC������޹�����4 */
    { 0x8E80, 0x3932, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC��������ڵ����� */
    { 0x8E90, 0x3948, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰC��������ڵ��ܷ� */
    { 0x8F00, 0x395E, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������й�����+ */
    { 0x8F10, 0x3974, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������й�����- */
    { 0x8F20, 0x398A, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������޹�����1 */
    { 0x8F30, 0x39A0, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������޹�����2 */
    { 0x8F40, 0x39B6, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������޹�����3 */
    { 0x8F50, 0x39CC, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������޹�����4 */
    { 0x8F80, 0x39E2, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������ڵ����� */
    { 0x8F90, 0x39F8, 4, 5, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ�������ڵ��ܷ� */
};

const struct item_t CODE item_energy_tab[] =
{
    { 0x9000, 0x0000, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA������й�����+ */
    { 0x9010, 0x0016, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA������й�����- */
    { 0x9020, 0x002C, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA������޹�����1 */
    { 0x9030, 0x0042, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA������޹�����2 */
    { 0x9040, 0x0058, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA������޹�����3 */
    { 0x9050, 0x006E, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA������޹�����4 */
    { 0x9060, 0x0084, 4, 5, fs_attribute(F_U32_VAH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA�������� */
    { 0x9070, 0x009A, 4, 5, fs_attribute(F_U32_VAH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA�����ڷ� */
    { 0x9080, 0x00B0, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA���й���+�� */
    { 0x9090, 0x00C6, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA���й���-�� */
    { 0x90A0, 0x00DC, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA������޹�+ */
    { 0x90B0, 0x00F2, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰA������޹�- */
    { 0x9100, 0x0108, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB������й�����+ */
    { 0x9110, 0x011E, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB������й�����- */
    { 0x9120, 0x0134, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB������޹�����1 */
    { 0x9130, 0x014A, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB������޹�����2 */
    { 0x9140, 0x0160, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB������޹�����3 */
    { 0x9150, 0x0176, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB������޹�����4 */
    { 0x9160, 0x018C, 4, 5, fs_attribute(F_U32_VAH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB�������� */
    { 0x9170, 0x01A2, 4, 5, fs_attribute(F_U32_VAH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB�����ڷ� */
    { 0x9180, 0x01B8, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB���й���+�� */
    { 0x9190, 0x01CE, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB���й���-�� */
    { 0x91A0, 0x01E4, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB������޹�+ */
    { 0x91B0, 0x01FA, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰB������޹�- */
    { 0x9200, 0x0210, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC������й�����+ */
    { 0x9210, 0x0226, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC������й�����- */
    { 0x9220, 0x023C, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC������޹�����1 */
    { 0x9230, 0x0252, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC������޹�����2 */
    { 0x9240, 0x0268, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC������޹�����3 */
    { 0x9250, 0x027E, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC������޹�����4 */
    { 0x9260, 0x0294, 4, 5, fs_attribute(F_U32_VAH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC�������� */
    { 0x9270, 0x02AA, 4, 5, fs_attribute(F_U32_VAH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC�����ڷ� */
    { 0x9280, 0x02C0, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC���й���+�� */
    { 0x9290, 0x02D6, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC���й���-�� */
    { 0x92A0, 0x02EC, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC������޹�+ */
    { 0x92B0, 0x0302, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰC������޹�- */
    { 0x9300, 0x0318, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ�������й�����+ */
    { 0x9310, 0x032E, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ�������й�����- */
    { 0x9320, 0x0344, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ�������޹�����1 */
    { 0x9330, 0x035A, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ�������޹�����2 */
    { 0x9340, 0x0370, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ�������޹�����3 */
    { 0x9350, 0x0386, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ�������޹�����4 */
    { 0x9360, 0x039C, 4, 5, fs_attribute(F_U32_VAH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ������ */
    { 0x9370, 0x03B2, 4, 5, fs_attribute(F_U32_VAH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ���ڷ� */
    { 0x9380, 0x03C8, 4, 5, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ�й���+�� */
    { 0x9390, 0x03DE, 4, 5, fs_attribute(F_U32_WH_SIGN, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ�й���-�� */
    { 0x93A0, 0x03F4, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ�������޹�+ */
    { 0x93B0, 0x040A, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ�������޹�- */
    { 0x93C0, 0x0420, 4, 5, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< ��ǰ�������޹�����1+2+3+4���� */
    { 0x9400, 0x0436, 4, 1, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< Activeenergyimport(+A)(interval) */
    { 0x9410, 0x043C, 4, 1, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< Activeenergyimport(+A)(interval) */
    { 0x9420, 0x0442, 4, 1, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< Reactiveenergyimport(+R)(QI+QII)(interval) */
    { 0x9430, 0x0448, 4, 1, fs_attribute(F_U32_VARH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< Reactiveenergyimport(+R)(QI+QII)(interval) */
    { 0x9480, 0x044E, 4, 1, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< Activeenergy��+��(interval) */
    { 0x9490, 0x0454, 4, 1, fs_attribute(F_U32_WH, notify_00, DEVICE_ENERGY, 1, 0, 1) }, /**< Activeenergy��-��(interval) */
};

const struct item_t CODE item_demand_tab[] =
{
    { 0xA010, 0x3D22, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< ActiveMD(+) */
    { 0xA020, 0x3D38, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< ActiveMD(-) */
    { 0xA030, 0x3D4E, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(+) */
    { 0xA040, 0x3D64, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(-) */
    { 0xA050, 0x3D7A, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QI) */
    { 0xA060, 0x3D90, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QII) */
    { 0xA070, 0x3DA6, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QIII) */
    { 0xA080, 0x3DBC, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QIV) */
    { 0xA090, 0x3DD2, 4, 5, fs_attribute(F_U32_VA, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(+) */
    { 0xA0A0, 0x3DE8, 4, 5, fs_attribute(F_U32_VA, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(-) */
    { 0xA0B0, 0x3DFE, 4, 5, fs_attribute(F_U32_VA, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(|QI+QIV|+|QII+QIII|) */
    { 0xA0C0, 0x3E14, 4, 5, fs_attribute(F_U32_VA, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(|QI+QIV|-|QII+QIII|) */
};

const struct item_t CODE item_accumulation_demand_tab[] =
{
    { 0xA210, 0x3F62, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ۻ��й������������ */
    { 0xA220, 0x3F78, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ۻ��й������������ */
    { 0xA230, 0x3F8E, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< �ۻ��޹������������ */
    { 0xA240, 0x3FA4, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< �ۻ��޹������������ */
    { 0xA250, 0x3FBA, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< �ۻ��޹�(QI)��������� */
    { 0xA260, 0x3FD0, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< �ۻ��޹�(QII)��������� */
    { 0xA270, 0x3FE6, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< �ۻ��޹�(QIII)��������� */
    { 0xA280, 0x3FFC, 4, 5, fs_attribute(F_U32_VAR, notify_00, 0, 1, 0, 1) }, /**< �ۻ��޹�(QIV)��������� */
    { 0xA290, 0x4012, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ۻ���������������� */
    { 0xA2A0, 0x4028, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ۻ����ڷ���������� */
    { 0xA2B0, 0x403E, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ۻ�����й���������� */
    { 0xA2C0, 0x4054, 4, 5, fs_attribute(F_U32_W, notify_00, 0, 1, 0, 1) }, /**< �ۻ������й���������� */
};

const struct item_t CODE item_demand_occuring_time_tab[] =
{
    { 0xB010, 0x4082, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ActiveMD(+)&occurringtime */
    { 0xB020, 0x409D, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ActiveMD(-)&occurringtime */
    { 0xB030, 0x40B8, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(+)&occurringtime */
    { 0xB040, 0x40D3, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(-)&occurringtime */
    { 0xB050, 0x40EE, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QI)&occurringtime */
    { 0xB060, 0x4109, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QII)&occurringtime */
    { 0xB070, 0x4124, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QIII)&occurringtime */
    { 0xB080, 0x413F, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ReactiveMD(QIV)&occurringtime */
    { 0xB090, 0x415A, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(+)&occurringtime */
    { 0xB0A0, 0x4175, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(-)&occurringtime */
    { 0xB0B0, 0x4190, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(|QI+QIV|+|QII+QIII|)&occurringtime */
    { 0xB0C0, 0x41AB, 5, 5, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ApparentMD(|QI+QIV|-|QII+QIII|)&occurringtime */
};

const struct item_t CODE item_Instantaneous_tab[] =
{
    { 0xC000, 0x0000, 4, 4, fs_attribute(F_U32_W, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�й����� */
    { 0xC010, 0x0012, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�޹����� */
    { 0xC020, 0x0024, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ���ڹ��� */
    { 0xC030, 0x0036, 2, 3, fs_attribute(F_U16_V, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC��˲ʱ��ѹ */
    { 0xC040, 0x003E, 2, 4, fs_attribute(F_U16_A, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC��˲ʱ���������ߵ��� */
    { 0xC044, 0x0048, 2, 1, fs_attribute(F_U16_A, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ʸ���͵���//wjz */
    { 0xC050, 0x004C, 2, 4, fs_attribute(F_U16_Pf, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�������� */
    { 0xC060, 0x0056, 2, 3, fs_attribute(F_U16_Ang, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC��˲ʱѹ���� */
    { 0xC063, 0x005E, 2, 1, fs_attribute(F_U16_Hz, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰ˲ʱƵ�� */
    { 0xC070, 0x0062, 2, 2, fs_attribute(F_U16_Ang, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC��˲��� */
    { 0xC0F0, 0x0068, 60, 1, fs_attribute(F_U16_Ang, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ���ɰ�����DLMS�ṹ */
    { 0xC0F1, 0x00A6, 4, 4, fs_attribute(F_FLOAT32_W, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�й����� */
    { 0xC0F5, 0x00B8, 4, 3, fs_attribute(F_FLOAT32_V, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC��˲ʱ��ѹ */
    { 0xC0F8, 0x00C6, 4, 4, fs_attribute(F_FLOAT32_A, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC��˲ʱ���������ߵ��� */
    { 0xC0FC, 0x00D8, 4, 1, fs_attribute(F_FLOAT32_A, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ʸ���͵���//wjz */
    { 0xC0FF, 0x00DE, 2, 1, fs_attribute(F_U16_V, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ص�ѹ */
    { 0xC100, 0x00E2, 4, 4, fs_attribute(F_U32_W, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�����й����� */
    { 0xC110, 0x00F4, 4, 4, fs_attribute(F_U32_W, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�����й����� */
    { 0xC120, 0x0106, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�޹�����1���� */
    { 0xC130, 0x0118, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�޹�����2���� */
    { 0xC140, 0x012A, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�޹�����3���� */
    { 0xC150, 0x013C, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�޹�����4���� */
    { 0xC160, 0x014E, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�����޹� */
    { 0xC170, 0x0160, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�����޹� */
    { 0xC180, 0x0172, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�������ڹ��� */
    { 0xC190, 0x0184, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�������ڹ��� */
    { 0xC1A0, 0x0196, 4, 4, fs_attribute(F_U32_W, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ��+���й����� */
    { 0xC1B0, 0x01A8, 4, 4, fs_attribute(F_U32_W_SIGN, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ��-���й����� */
    { 0xC1C0, 0x01BA, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ��˲ʱ�����ڹ��� */
    { 0xC200, 0x01CC, 2, 3, fs_attribute(F_U16_V, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC���ѹ���ֵ */
    { 0xC210, 0x01D4, 2, 3, fs_attribute(F_U16_A, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC��������ֵ */
    { 0xC220, 0x01DC, 4, 4, fs_attribute(F_U32_W, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�������й����ֵ */
    { 0xC230, 0x01EE, 4, 4, fs_attribute(F_U32_W, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܷ����й����ֵ */
    { 0xC240, 0x0200, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�������޹����ֵ */
    { 0xC250, 0x0212, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܷ����޹����ֵ */
    { 0xC260, 0x0224, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����1���ֵ */
    { 0xC270, 0x0236, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����2���ֵ */
    { 0xC280, 0x0248, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����3���ֵ */
    { 0xC290, 0x025A, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����4���ֵ */
    { 0xC2A0, 0x026C, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���������ڹ������ֵ */
    { 0xC2B0, 0x027E, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܷ������ڹ������ֵ */
    { 0xC2C0, 0x0290, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰ���������ڹ���(abs(QI+QIV)+(abs(QII+QIII))���ֵ */
    { 0xC2D0, 0x02A2, 2, 4, fs_attribute(F_U16_Pf, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܹ����������ֵ */
    { 0xC2E3, 0x02AC, 2, 1, fs_attribute(F_U16_Hz, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰƵ�����ֵ */
    { 0xC300, 0x02B0, 2, 3, fs_attribute(F_U16_V, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC���ѹ��Сֵ */
    { 0xC310, 0x02B8, 2, 3, fs_attribute(F_U16_A, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�������Сֵ */
    { 0xC320, 0x02C0, 4, 4, fs_attribute(F_U32_W, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�������й���Сֵ */
    { 0xC330, 0x02D2, 4, 4, fs_attribute(F_U32_W, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܷ����й���Сֵ */
    { 0xC340, 0x02E4, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�������޹���Сֵ */
    { 0xC350, 0x02F6, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܷ����޹���Сֵ */
    { 0xC360, 0x0308, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����1��Сֵ */
    { 0xC370, 0x031A, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����2��Сֵ */
    { 0xC380, 0x032C, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����3��Сֵ */
    { 0xC390, 0x033E, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����4��Сֵ */
    { 0xC3A0, 0x0350, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���������ڹ�����Сֵ */
    { 0xC3B0, 0x0362, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܷ������ڹ�����Сֵ */
    { 0xC3C0, 0x0374, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰ���������ڹ���(abs(QI+QIV)+(abs(QII+QIII))��Сֵ */
    { 0xC3D0, 0x0386, 2, 4, fs_attribute(F_U16_Pf, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܹ���������Сֵ */
    { 0xC3E3, 0x0390, 2, 1, fs_attribute(F_U16_Hz, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰƵ����Сֵ */
    { 0xC400, 0x0394, 2, 3, fs_attribute(F_U16_V, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC���ѹ�ۼӺ� */
    { 0xC410, 0x039C, 2, 3, fs_attribute(F_U16_A, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC������ۼӺ� */
    { 0xC420, 0x03A4, 4, 4, fs_attribute(F_U32_W, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�������й��ۼӺ� */
    { 0xC430, 0x03B6, 4, 4, fs_attribute(F_U32_W, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܷ����й��ۼӺ� */
    { 0xC440, 0x03C8, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�������޹��ۼӺ� */
    { 0xC450, 0x03DA, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܷ����޹��ۼӺ� */
    { 0xC460, 0x03EC, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����1ƽ��ֵ */
    { 0xC470, 0x03FE, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����2ƽ��ֵ */
    { 0xC480, 0x0410, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����3ƽ��ֵ */
    { 0xC490, 0x0422, 4, 4, fs_attribute(F_U32_VAR, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���޹�����4ƽ��ֵ */
    { 0xC4A0, 0x0434, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ���������ڹ���ƽ��ֵ */
    { 0xC4B0, 0x0446, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܷ������ڹ���ƽ��ֵ */
    { 0xC4C0, 0x0458, 4, 4, fs_attribute(F_U32_VA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰ���������ڹ���(abs(QI+QIV)+(abs(QII+QIII))ƽ��ֵ */
    { 0xC4D0, 0x046A, 2, 4, fs_attribute(F_U16_Pf, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC�ࡢ�ܹ�������ƽ��ֵ */
    { 0xC4E3, 0x0474, 2, 1, fs_attribute(F_U16_Hz, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰƵ��ƽ��ֵ */
    { 0xC500, 0x0478, 4, 4, fs_attribute(F_U32_Ah, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< A�ࡢB�ࡢC�ࡢ��һСʱ�����ۼӺ� */
    { 0xC600, 0x048A, 2, 3, fs_attribute(F_U16_V, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ǰA�ࡢB�ࡢC��ƽ����ѹ */
    { 0xC640, 0x0492, 2, 1, fs_attribute(F_U16_A, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ��ͨ������ */
    { 0xC900, 0x0496, 2, 11, fs_attribute(F_U16_V, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< A��1��3��5��7��9��11��13��15��17��19��THD��г����ѹֵ */
    { 0xC910, 0x04AE, 2, 11, fs_attribute(F_U16_V, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< B��1��3��5��7��9��11��13��15��17��19��THD��г����ѹֵ */
    { 0xC920, 0x04C6, 2, 11, fs_attribute(F_U16_V, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< C��1��3��5��7��9��11��13��15��17��19��THD��г����ѹֵ */
    { 0xC930, 0x04DE, 2, 11, fs_attribute(F_U16_A, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< A��1��3��5��7��9��11��13��15��17��19��THD��г������ֵ */
    { 0xC940, 0x04F6, 2, 11, fs_attribute(F_U16_A, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< B��1��3��5��7��9��11��13��15��17��19��THD��г������ֵ */
    { 0xC950, 0x050E, 2, 11, fs_attribute(F_U16_A, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< C��1��3��5��7��9��11��13��15��17��19��THD��г������ֵ */
};

const struct item_t CODE item_general_tab[] =
{
    { 0xCA00, 0x0000, 7, 1, fs_attribute(F_OCT_PARA, notify_01, DEVICE_RTC, 1, 0, 1) }, /**< ��ǰʱ�����ڸ���ʾ��ʹ�� */
    { 0xCA03, 0x0009, 4, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_RTC, 1, 0, 1) }, /**< ��ǰʱ������ */
    { 0xCA10, 0x000F, 7, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_RTC, 1, 0, 1) }, /**< ��ǰʱ�����ڸ���ʾ��ʹ�� */
    { 0xCA13, 0x0018, 4, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_RTC, 1, 0, 1) }, /**< ��ǰʱ������ */
    { 0xCA20, 0x001E, 1, 1, fs_attribute(F_U08_PARA, notify_04, DEVICE_VIRTUAL_NOTIFY, 1, 0, 1) }, /**< �ϵ�ʱ������֪ͨ�� */
    { 0xCA30, 0x0021, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_SNAPSHOT, 1, 0, 1) }, /**< EventObjectStandardEventsLogeventcode */
    { 0xCA40, 0x0024, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< EventParameter(Sub-events) */
    { 0xCA41, 0x0027, 2, 1, fs_attribute(F_U16_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< EventParameter1(PowerQualityLog)Magnitude */
    { 0xCA42, 0x002B, 4, 1, fs_attribute(F_U32_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< EventParameter2(PowerQualityLog)Duration */
    { 0xCA43, 0x0031, 4, 1, fs_attribute(F_U32_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< EventParameter2(PowerFailureLog)Duration */
    { 0xCA44, 0x0037, 2, 1, fs_attribute(F_U32_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< Numberoflongpowerfailuresinanyphase */
    { 0xCB00, 0x003B, 5, 1, fs_attribute(F_ERROR, notify_00, 0, 1, 0, 1) }, /**< threshold_active(4)+emergency_profile_active(1) */
    { 0xCB10, 0x0042, 2, 5, fs_attribute(F_U16_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< Un */
};

const struct item_t CODE item_prepay_ram_tab[] =
{
    { 0xCC00, 0x0000, 1, 1, fs_attribute(F_ERROR, notify_00, DEVICE_TOKEN, 1, 0, 1) }, /**< tokencode; */
    { 0xCC01, 0x0003, 1, 1, fs_attribute(F_ERROR, notify_06, DEVICE_METER, 1, 0, 1) }, /**< ��ʾ������ģ�鷢����Ϣ��ʼ��������; */
    { 0xCC02, 0x0006, 1, 1, fs_attribute(F_ERROR, notify_06, DEVICE_METER, 1, 0, 1) }, /**< ��ʾ������ģ�鷢����Ϣ���ڰ���10s���޲������������尴������; */
    { 0xCC80, 0x0009, 1, 2, fs_attribute(F_ERROR, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< activeaccountandpassiveaccount */
    { 0xCC82, 0x000D, 1, 8, fs_attribute(F_ERROR, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< credit1-4withactiveaccountandcredit5-8withpassiveaccount */
    { 0xCC8A, 0x0017, 1, 18, fs_attribute(F_ERROR, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< charge1-4withactiveaccountandcharge5-8withpassiveaccount */
    { 0xCCA0, 0x002B, 1, 1, fs_attribute(F_ERROR, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< ������ģʽ */
    { 0xCCA1, 0x002E, 8, 1, fs_attribute(F_ERROR, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< ������ */
    { 0xCCA2, 0x0038, 8, 1, fs_attribute(F_ERROR, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< ��������� */
    { 0xCCA3, 0x0042, 18, 1, fs_attribute(F_ERROR, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< ��ֵ */
    { 0xCCA4, 0x0056, 1, 1, fs_attribute(F_ERROR, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< �̵������� */
    { 0xCCA5, 0x0059, 1, 1, fs_attribute(F_ERROR, notify_00, DEVICE_TOKEN, 1, 0, 1) }, /**< ���¼���¼ */
    { 0xCCA6, 0x005C, 1, 1, fs_attribute(F_ERROR, notify_00, DEVICE_PREPAY, 1, 0, 1) }, /**< ����͸֧ */
    { 0xCCA7, 0x005F, 1, 1, fs_attribute(F_ERROR, notify_00, DEVICE_TOKEN, 1, 0, 1) }, /**< ȡ���������� */
    { 0xCCA8, 0x0062, 1, 1, fs_attribute(F_ERROR, notify_00, DEVICE_TOKEN, 1, 0, 1) }, /**< �������Ȳ��� */
    { 0xCCA9, 0x0065, 1, 1, fs_attribute(F_ERROR, notify_00, DEVICE_TOKEN, 1, 0, 1) }, /**< ������ǡ�����ť�Ǽ�� */
    { 0xCCB0, 0x0068, 11, 10, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��1-10�γ�ֵToken�� */
    { 0xCCC0, 0x00D8, 3, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��1-5�γ�ֵ���� */
    { 0xCCD0, 0x00E9, 3, 5, fs_attribute(F_OCT_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��1-5�γ�ֵʱ�� */
    { 0xCCE0, 0x00FA, 8, 5, fs_attribute(F_S64_PARA, notify_00, DEVICE_SNAPSHOTLIB, 1, 0, 1) }, /**< ��1-5�γ�ֵ��� */
    { 0xCF00, 0x0124, 1, 2, fs_attribute(F_ERROR, notify_02, DEVICE_METER_CMD, 1, 0, 1) }, /**< �����+�¼����� */
    { 0xCF02, 0x0128, 1, 3, fs_attribute(F_ERROR, notify_00, DEVICE_METER_CMD, 1, 0, 1) }, /**< �������� */
    { 0xCF06, 0x012D, 1, 1, fs_attribute(F_VIS_PARA, notify_00, DEVICE_METER_CMD, 1, 0, 1) }, /**< �ֶ����� */
    { 0xCF0A, 0x0130, 4, 1, fs_attribute(F_U32_PARA, notify_05, DEVICE_METER, 1, 0, 1) }, /**< У���ʽ�� */
    { 0xCF0B, 0x0136, 30, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ���ܰ汾��ˮ�� */
    { 0xCF10, 0x0156, 20, 2, fs_attribute(F_OCT_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ����汾�� */
    { 0xCF12, 0x0180, 30, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< �ڲ�����汾�� */
    { 0xCF20, 0x01A0, 4, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ����У���� */
    { 0xCF21, 0x01A6, 2, 1, fs_attribute(F_U16_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ����ģʽ���� */
    { 0xCF22, 0x01AA, 17, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< COSEMlogicaldevicename */
    { 0xCF23, 0x01BD, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ����ģʽ����//wjz */
    { 0xCF29, 0x01C0, 4, 1, fs_attribute(F_U32_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ���IO�ڼ��״̬ */
    { 0xCF2A, 0x01C6, 2, 1, fs_attribute(F_U16_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< оƬ�Լ�״̬ */
    { 0xCF2B, 0x01CA, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< �������� LED�ơ���������Һ�� */
    { 0xCF2C, 0x01CD, 4, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ˲�r�� */
    { 0xCF2E, 0x01D3, 1, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< �¼����� */
    { 0xCF2F, 0x01D6, 1, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_RTC, 1, 0, 1) }, /**< �������л� */
    { 0xCF30, 0x01D9, 1, 14, fs_attribute(F_U08_PARA, notify_00, DEVICE_PUSH, 1, 0, 1) }, /**< GPRSģ����hx645id0x5056��ȡ������ */
    { 0xCF3F, 0x01E9, 1, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< ��λ����ͨ��1~7���ͱ�־ */
    { 0xCF40, 0x01EC, 7, 7, fs_attribute(F_OCT_PARA, notify_00, DEVICE_PUSH, 1, 0, 1) }, /**< ����ͨ��1~7����1�߼���ӳ���������ͨ����������ͨ���߼���logical_name */
    { 0xCF56, 0x021F, 4, 1, fs_attribute(F_U32_PARA, notify_00, DEVICE_ALARM, 1, 0, 1) }, /**< ErrorRegister */
    { 0xCF57, 0x0225, 4, 4, fs_attribute(F_U32_PARA, notify_00, DEVICE_ALARM, 1, 0, 1) }, /**< �澯12�Ĵ����澯12�����Ĵ��� */
    { 0xCF5B, 0x0237, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_ALARM, 1, 0, 1) }, /**< �澯�����Ĵ��������仯��־AlarmDescriptor���ͱ仯��־ */
    { 0xCF5C, 0x023A, 4, 1, fs_attribute(F_U32_PARA, notify_00, DEVICE_ALARM, 1, 0, 1) }, /**< �澯�Ĵ���hx */
    { 0xCF5D, 0x0240, 4, 1, fs_attribute(F_U32_PARA, notify_00, DEVICE_ALARM, 1, 0, 1) }, /**< ErrorRegisterhx */
    { 0xCF70, 0x0246, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< �ź�ǿ��CSQ */
    { 0xCF71, 0x0249, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< �ź�ǿ�� */
    { 0xCF72, 0x024C, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< ģ�鹤��״̬ */
    { 0xCF73, 0x024F, 65, 1, fs_attribute(F_VIS_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< ģ������汾�� */
    { 0xCF74, 0x0292, 16, 1, fs_attribute(F_VIS_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< GPRSģ���IMEI�� */
    { 0xCF75, 0x02A4, 33, 1, fs_attribute(F_VIS_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< ģ��Ӳ���汾�� */
    { 0xCF76, 0x02C7, 33, 1, fs_attribute(F_VIS_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< ģ���ⲿ����汾�� */
    { 0xCF77, 0x02EA, 4, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< ģ���¼�״̬�� */
    { 0xCF78, 0x02F0, 1, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< �������� */
    { 0xCF79, 0x02F3, 17, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< ģ��ע�Ἧ������ַ */
    { 0xCF7A, 0x0306, 1, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< �ز�ע����Ϣ */
    { 0xCF7B, 0x0309, 2, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< ������MAC��ַ���ز��� */
    { 0xCF7D, 0x030D, 7, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< ����ʱ���ʽ:bcd���ʱ�������� */
    { 0xCF7E, 0x0316, 1, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< gprsģ��������ı�־ */
    { 0xCF7F, 0x0319, 4, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< ģ��ip��ַ */
    { 0xCF80, 0x031F, 32, 5, fs_attribute(F_VIS_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< ��վ�绰����1~5 */
    { 0xCF85, 0x03C1, 44, 3, fs_attribute(F_VIS_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< gprs���������� */
    { 0xCF90, 0x0447, 1, 2, fs_attribute(F_OCT_PARA, notify_00, DEVICE_INSTANPACK, 1, 0, 1) }, /**< InstantaneousValues */
    { 0xCF92, 0x044B, 1, 6, fs_attribute(F_OCT_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ActivefirmwareIdentifier */
    { 0xD000, 0x0453, 1, 10, fs_attribute(F_U08_PARA, notify_00, DEVICE_METERSTATE, 1, 0, 1) }, /**< AMI״̬�� */
    { 0xD010, 0x045F, 49, 8, fs_attribute(F_OCT_PARA, notify_00, DEVICE_MBUS, 1, 0, 1) }, /**< M-BusDeviceID1channel1 */
    { 0xD01C, 0x05E9, 1, 4, fs_attribute(F_ENUM_PARA, notify_00, DEVICE_MBUS, 1, 0, 1) }, /**< EventObjects-M-BusMasterControllogs1 */
    { 0xD020, 0x05EF, 210, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_MBUS, 1, 0, 1) }, /**< M-BusDisconnectorscripttable */
    { 0xD030, 0x06C3, 4, 3, fs_attribute(F_OCT_PARA, notify_00, DEVICE_METER_PARA, 1, 0, 1) }, /**< �ͻ��˵�FC */
    { 0xD040, 0x06D3, 2, 1, fs_attribute(F_U16_PARA, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< ����ID�ⲿģ�����ü̵���������ͨ�ýӿ� */
    { 0xD041, 0x06D7, 2, 1, fs_attribute(F_U16_PARA, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< ����ID�ⲿģ��ȡ���̵���������ͨ�ýӿ� */
    { 0xD042, 0x06DB, 1, 1, fs_attribute(F_OCT_PARA, notify_01, DEVICE_RELAY, 1, 0, 1) }, /**< Tokenģ�����ü̵��������Ľӿ�(STS�̵�������) */
    { 0xD043, 0x06DE, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< ����ID��ȡ�̵����������� */
    { 0xD044, 0x06E1, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< ����ID��ȡ�̵���״̬ */
    { 0xD045, 0x06E4, 4, 1, fs_attribute(F_U32_PARA, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< ����ID��ȡ�̵��������¼���ֵ */
    { 0xD046, 0x06EA, 2, 1, fs_attribute(F_U16_PARA, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< ����ID��ȡ�̵��������¼���ʱ */
    { 0xD047, 0x06EE, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< ǿ�ƺ�բ */
    { 0xD048, 0x06F1, 1, 1, fs_attribute(F_U08_PARA, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< ���ɿ���ʹ�� */
    { 0xD622, 0x06F8, 1, 1, fs_attribute(F_BOOL_PARA, notify_00, DEVICE_RELAY, 1, 0, 1) }, /**< �̵�����������ģʽ����״̬ */
    { 0xD630, 0x06FB, 1, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_645, 1, 0, 1) }, /**< cp\pt����¼�֪ͨ */
    { 0xD640, 0x06FE, 4, 1, fs_attribute(F_U32_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ������������ */
    { 0xD650, 0x0704, 4, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_METER, 1, 0, 1) }, /**< ������У�� */
    { 0xD654, 0x070A, 1, 1, fs_attribute(F_OCT_PARA, notify_13, DEVICE_METER, 1, 0, 1) }, /**< ����ID,֪ͨDCU���Է����ⲿ����֡��ģ�� */
    { 0xD655, 0x070D, 1, 1, fs_attribute(F_OCT_PARA, notify_14, DEVICE_METER, 1, 0, 1) }, /**< ����ID,֪ͨDCU���Է���ģ��Ӧ�����ݸ�IRͨѶ�� */
    { 0xD656, 0x0710, 1, 1, fs_attribute(F_OCT_PARA, notify_15, DEVICE_METER, 1, 0, 1) }, /**< ����ID,֪ͨDCU���Է���ģ��Ӧ�����ݸ�RS485ͨѶ�� */
    { 0xD657, 0x0713, 1, 1, fs_attribute(F_OCT_PARA, notify_16, DEVICE_METER, 1, 0, 1) }, /**< ����ID,֪ͨDCU���Է���ģ��Ӧ�����ݸ�remoteͨѶ�� */
    { 0xD658, 0x0716, 2, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_PUSH, 1, 0, 1) }, /**< PUSH RAM FS */
    { 0xD659, 0x071A, 2, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_DCU, 1, 0, 1) }, /**< DCU RAM FS */
    { 0xD660, 0x071E, 4, 1, fs_attribute(F_OCT_PARA, notify_00, DEVICE_INSTANTANEOUS, 1, 0, 1) }, /**< ģ��ĵ��ݡ����ֵ��ǰ��2���ֽ�Ϊ���ݣ�nH��������2���ֽ�Ϊ���(nF) */
};

const struct item_t CODE item_prepay_tab[] =
{
    { 0xDA00, 0x4342, 10, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ��¼Token */
    { 0xDA01, 0x434E, 13, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< STS��Կ */
    { 0xDA02, 0x435D, 151, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< TID����+TID��¼ */
    { 0xDA03, 0x43F6, 4, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ����� */
    { 0xDA04, 0x43FC, 8, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ���಻ƽ��� */
    { 0xDA05, 0x4406, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< TID���� */
    { 0xDA06, 0x4409, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ���ע����ʶ */
    { 0xDA07, 0x440C, 11, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ���ע�������� */
    { 0xDA08, 0x4419, 4, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< SGC��  */
    { 0xDA09, 0x441F, 2, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �����޸���Կ�ȴ�ʱ�� */
    { 0xDA10, 0x4423, 1, 1, fs_attribute(F_ENUM_PARA, notify_00, 0, 1, 0, 1) }, /**< STS�����㷨 */
    { 0xDA11, 0x4426, 1, 1, fs_attribute(F_U08_PARA, notify_00, 0, 1, 0, 1) }, /**< �޸���Կ���� */
    { 0xDA12, 0x4429, 1, 1, fs_attribute(F_U08_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ԿʧЧ�ж����� */
    { 0xDA13, 0x442C, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< STS��֤��ʼ�� */
    { 0xDA14, 0x442F, 2, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ����CIU����ʱ�� */
    { 0xDA15, 0x4433, 62, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ����CIU��ʾ�� */
    { 0xDA16, 0x4473, 3, 1, fs_attribute(F_VIS_PARA, notify_00, 0, 1, 0, 1) }, /**< ���������� */
    { 0xDA17, 0x4478, 1, 1, fs_attribute(F_U08_PARA, notify_00, 0, 1, 0, 1) }, /**< ��Կ���� */
    { 0xDA18, 0x447B, 1, 1, fs_attribute(F_U08_PARA, notify_00, 0, 1, 0, 1) }, /**< STS��Կ�汾�� */
    { 0xDA19, 0x447E, 4, 1, fs_attribute(F_VIS_PARA, notify_00, 0, 1, 0, 1) }, /**< ���汾 */
    { 0xDA21, 0x4484, 1, 1, fs_attribute(F_U08_PARA, notify_00, 0, 1, 0, 1) }, /**< TCT��token�������ͣ� */
    { 0xDA22, 0x4487, 3, 1, fs_attribute(F_VIS_PARA, notify_00, 0, 1, 0, 1) }, /**< STS���̴��� */
    { 0xDA23, 0x448C, 7, 1, fs_attribute(F_VIS_PARA, notify_00, 0, 1, 0, 1) }, /**< IIN��IssuerIdentificationNumber�� */
    { 0xDA24, 0x4495, 2, 1, fs_attribute(F_U16_PARA, notify_00, 0, 1, 0, 1) }, /**< CIU���ƶ�ʱͬ������ */
    { 0xDD00, 0x4499, 37, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �Ѻ�ʱ��=1+6*6 */
    { 0xDD01, 0x44C0, 121, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �Ѻýڼ���=1+4*30 */
    { 0xDD02, 0x453B, 33, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ��ǰ���� */
    { 0xDD03, 0x455E, 33, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �����׽��� */
    { 0xDD04, 0x4581, 4, 1, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ���㱨����ֵ1 */
    { 0xDD05, 0x4587, 4, 1, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ���㱨����ֵ2 */
    { 0xDD06, 0x458D, 4, 1, fs_attribute(F_U32_PARA, notify_00, 0, 1, 0, 1) }, /**< ���㱨����ֵ3 */
    { 0xDD07, 0x4593, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �Ƿ�ʹ���Ѻ�ģʽ */
    { 0xDD08, 0x4596, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �Ƿ���ȡ���������� */
    { 0xDD09, 0x4599, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �Ѻ������� */
    { 0xDD0A, 0x459C, 120, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�0���� */
    { 0xDD0B, 0x4616, 120, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�1���� */
    { 0xDD0E, 0x4690, 56, 4, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�0-CREDIT1-4 */
    { 0xDD12, 0x4772, 56, 4, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�1-CREDIT1-4 */
    { 0xDD16, 0x4854, 150, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�0-CHARGE1 */
    { 0xDD17, 0x48EC, 150, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�0-CHARGE2 */
    { 0xDD18, 0x4984, 150, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�0-CHARGE3 */
    { 0xDD19, 0x4A1C, 150, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�0-CHARGE4 */
    { 0xDD1A, 0x4AB4, 150, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�1-CHARGE1 */
    { 0xDD1B, 0x4B4C, 150, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�1-CHARGE2 */
    { 0xDD1C, 0x4BE4, 150, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�1-CHARGE3 */
    { 0xDD1D, 0x4C7C, 150, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �˻�1-CHARGE4 */
    { 0xDD30, 0x4D14, 8, 1, fs_attribute(F_U32_PARA, notify_01, 0, 1, 0, 1) }, /**< ���ڻ������ */
    { 0xDD31, 0x4D1E, 4, 1, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< ����͸֧��� */
    { 0xDD32, 0x4D24, 8, 1, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< ���γ�ֵ���/���� */
    { 0xDD33, 0x4D2E, 8, 1, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< �ܳ�ֵ��� */
    { 0xDD34, 0x4D38, 2, 2, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< mode_status */
    { 0xDD36, 0x4D3E, 4, 2, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< clearance_threshold */
    { 0xDD38, 0x4D48, 49, 2, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< credit_charge_config=1+3*16 */
    { 0xDD3A, 0x4DAC, 9, 2, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< token_gateway_config=1+2*4 */
    { 0xDD3C, 0x4DC0, 12, 2, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< active time */
    { 0xDD3E, 0x4DDA, 12, 2, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< close time */
    { 0xDD40, 0x4DF4, 5, 2, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< currency */
    { 0xDD42, 0x4E00, 2, 2, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< max_provision */
    { 0xDD44, 0x4E06, 4, 2, fs_attribute(F_U32_PARA, notify_02, 0, 1, 0, 1) }, /**< max_provision_period */
};

const struct item_t CODE item_para_power_off_tab[] =
{
    { 0xE001, 0x4EFA, 7, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ����ʱ�� */
    { 0xE002, 0x4F03, 7, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ��������ʱ��//wjz */
    { 0xE003, 0x4F0C, 192, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ��һ�ο���״̬���� */
    { 0xE004, 0x4FCE, 136, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �ڶ��ο���״̬���� */
    { 0xE005, 0x5058, 14, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ���ɴ洢�������� */
    { 0xE008, 0x5068, 19, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �澯��ؼĴ��� */
    { 0xE009, 0x507D, 1, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< ����ε�ص��¼� */
    { 0xE00A, 0x5080, 4, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �ź�ǿ���¼���Ϣ */
    { 0xE00B, 0x5086, 24, 1, fs_attribute(F_OCT_PARA, notify_00, 0, 1, 0, 1) }, /**< �����¼���ֵ��Ϣ */
    { 0xE030, 0x50A0, 1, 2, fs_attribute(F_U08_PARA, notify_00, 0, 1, 0, 1) }, /**< �̵���״̬ + ����ԭ�� */
};

const struct item_t CODE item_profile_log_tab[] =
{
    { 0xF000, 0x0000, 128, 1000, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< ���������Ϣ */
    { 0xF021, 0x0080, 50, 1000, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< �¶��� */
    { 0xF080, 0x00B2, 50, 3120, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< ��������1 */
    { 0xF081, 0x00E4, 50, 3120, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< ��������2 */
    { 0xF082, 0x0116, 50, 3120, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< ��������3 */
    { 0xF083, 0x0148, 50, 3120, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< ��������4 */
    { 0xF084, 0x017A, 50, 3120, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< ��������5 */
    { 0xF085, 0x01AC, 50, 3120, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< ��������6 */
    { 0xF086, 0x01DE, 50, 3120, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< ��������7 */
    { 0xF087, 0x0210, 50, 3120, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< ��������8 */
    { 0xF088, 0x0242, 50, 3120, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< ��������9�������ߣ� */
    { 0xF089, 0x0274, 50, 3120, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< ��������10�������ߣ� */
    { 0xF100, 0x02A6, 4, 200, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��׼����ˮ���¼� */
    { 0xF101, 0x02AA, 4, 200, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��թ����ˮ���¼� */
    { 0xF102, 0x02AE, 4, 200, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��������ˮ���¼� */
    { 0xF103, 0x02B2, 4, 200, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��������ˮ���¼� */
    { 0xF104, 0x02B6, 4, 200, fs_attribute(F_OCT_PARA, notify_12, 0, 0, 0, 0) }, /**< ͨѶ����ˮ���¼� */
    { 0xF10B, 0x02BA, 4, 200, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��ˮ�˰ͻ�˹̹�����¼� */
};

const struct item_t CODE item_event_log_tab[] =
{
    { 0xF110, 0x02BE, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ����ר���¼ */
    { 0xF111, 0x02C2, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< �̵���ר���¼ */
    { 0xF112, 0x02C6, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ������ר���¼ */
    { 0xF113, 0x02CA, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< A��ʧѹר���¼ */
    { 0xF114, 0x02CE, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< B��ʧѹר���¼ */
    { 0xF115, 0x02D2, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< C��ʧѹר���¼ */
    { 0xF116, 0x02D6, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< A��Ƿѹר���¼ */
    { 0xF117, 0x02DA, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< B��Ƿѹר���¼ */
    { 0xF118, 0x02DE, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< C��Ƿѹר���¼ */
    { 0xF119, 0x02E2, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< A���ѹר���¼ */
    { 0xF11A, 0x02E6, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< B���ѹר���¼ */
    { 0xF11B, 0x02EA, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< C���ѹר���¼ */
    { 0xF11C, 0x02EE, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< A�����ר���¼ */
    { 0xF11D, 0x02F2, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< B�����ר���¼ */
    { 0xF11E, 0x02F6, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< C�����ר���¼ */
    { 0xF11F, 0x02FA, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< A�����ר���¼ */
    { 0xF120, 0x02FE, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< B�����ר���¼ */
    { 0xF121, 0x0302, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< C�����ר���¼ */
    { 0xF122, 0x0306, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< A���������ר���¼ */
    { 0xF123, 0x030A, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< B���������ר���¼ */
    { 0xF124, 0x030E, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< C���������ר���¼ */
    { 0xF125, 0x0312, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��ص�ѹ��ר���¼ */
    { 0xF126, 0x0316, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��ģ���ר���¼ */
    { 0xF127, 0x031A, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< �����ר���¼ */
    { 0xF128, 0x031E, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ���˸�ר���¼ */
    { 0xF129, 0x0322, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ȱ����ר���¼ */
    { 0xF12A, 0x0326, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< �����й���������ר���¼? */
    { 0xF12B, 0x032A, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��ѹ������ר���¼ */
    { 0xF12C, 0x032E, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��ѹ��ƽ��ר���¼ */
    { 0xF12D, 0x0332, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ���ʲ�ƽ��ר���¼ */
    { 0xF12E, 0x0336, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< �������������ר���¼ */
    { 0xF12F, 0x033A, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��·ר���¼ */
    { 0xF130, 0x033E, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ǿ�ų�ר���¼ */
    { 0xF131, 0x0342, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ����ר���¼ */
    { 0xF132, 0x0346, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ���Է�ר���¼ */
    { 0xF133, 0x034A, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ���ʷ���ר���¼ */
    { 0xF170, 0x034E, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< �����ר���¼ */
    { 0xF171, 0x0352, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ������λר���¼(�ֶ���ͨѶ���½�)? */
    { 0xF172, 0x0356, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ���¼���־ר���¼? */
    { 0xF173, 0x035A, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ����ר���¼? */
    { 0xF174, 0x035E, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< �޸�����ר���¼? */
    { 0xF175, 0x0362, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< Уʱר���¼ */
    { 0xF176, 0x0366, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ͨѶר���¼������ͨѶ�ɹ��� */
    { 0xF177, 0x036A, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< TOU����ר���¼? */
    { 0xF178, 0x036E, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< �̼�����ר���¼(��������ɹ�)? */
    { 0xF179, 0x0372, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< EEPROM����ר���¼ */
    { 0xF17A, 0x0376, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< FLASH����ר���¼ */
    { 0xF17B, 0x037A, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��������У�����ר���¼ */
    { 0xF17C, 0x037E, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< �޸�ctptר���¼� */
    { 0xF17D, 0x0382, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< �̵����Ͽ�ר���¼ */
    { 0xF17E, 0x0386, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< �̵����պ�ר���¼ */
    { 0xF17F, 0x038A, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ��ֵר���¼ */
    { 0xF180, 0x038E, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< ����TOKEN��ר���¼ */
    { 0xF181, 0x0392, 4, 10, fs_attribute(F_OCT_PARA, notify_11, 0, 0, 0, 0) }, /**< Ԥ�����˻��л�ר���¼ */
    { 0xF200, 0x0396, 1, 10, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< һ��������Ӧ�ò��֡����ʹ�� */
    { 0xF201, 0x0397, 1, 10, fs_attribute(F_OCT_PARA, notify_00, 0, 0, 0, 0) }, /**< һ����������·���֡����ʹ�� */
};

extern const struct file_ops_t CODE mirror_file_ops;
extern const struct file_ops_t CODE ram_file_ops;
extern const struct file_ops_t CODE char_file_ops;
extern const struct file_ops_t CODE log_file_ops;
extern const struct file_ops_t CODE direct_file_ops;
extern const struct file_ops_t CODE simulate_file_ops;
const struct partition_t CODE file_partitions[] =
{
    { &char_file_ops, item_char_device_tab, array_count(item_char_device_tab), 0x0000, DEVICE_CHAR },
    { &mirror_file_ops, item_para_calibration_tab, array_count(item_para_calibration_tab), 0x01E1, DEVICE_EEPROM },
    { &mirror_file_ops, item_energy_powoff_save_tab, array_count(item_energy_powoff_save_tab), 0x0198, DEVICE_EEPROM },
    { &mirror_file_ops, item_energySave_tab, array_count(item_energySave_tab), 0x02C4, DEVICE_EEPROM },
    { &mirror_file_ops, item_demand_tab, array_count(item_demand_tab), 0x0108, DEVICE_EEPROM },
    { &mirror_file_ops, item_demand_occuring_time_tab, array_count(item_demand_occuring_time_tab), 0x0144, DEVICE_EEPROM },
    { &mirror_file_ops, item_accumulation_demand_tab, array_count(item_accumulation_demand_tab), 0x0000, DEVICE_EEPROM },
    { &mirror_file_ops, item_para1_tab, array_count(item_para1_tab), 0x0000, DEVICE_EEPROM },
    { &mirror_file_ops, item_para2_tab, array_count(item_para2_tab), 0x0000, DEVICE_EEPROM },
    { &mirror_file_ops, item_prepay_tab, array_count(item_prepay_tab), 0x0000, DEVICE_EEPROM },
    { &mirror_file_ops, item_history_tab, array_count(item_history_tab), 0x0000, DEVICE_EEPROM },
    { &mirror_file_ops, item_RamMap_tab, array_count(item_RamMap_tab), 0x0000, DEVICE_EEPROM },
    { &mirror_file_ops, item_comm_tab, array_count(item_comm_tab), 0x0000, DEVICE_EEPROM },
    { &mirror_file_ops, item_para_power_off_tab, array_count(item_para_power_off_tab), 0x0000, DEVICE_EEPROM },
    { &mirror_file_ops, item_tariff_tab, array_count(item_tariff_tab), 0x0000, DEVICE_EEPROM },
    { &log_file_ops, item_profile_log_tab, array_count(item_profile_log_tab), 0x0000, DEVICE_FLASH },
    { &log_file_ops, item_event_log_tab, array_count(item_event_log_tab), 0x0000, DEVICE_FLASH },
    { &ram_file_ops, item_Instantaneous_tab, array_count(item_Instantaneous_tab), 0x0000, DEVICE_RAM },
    { &ram_file_ops, item_energy_tab, array_count(item_energy_tab), 0x0000, DEVICE_RAM },
    { &ram_file_ops, item_demandram_tab, array_count(item_demandram_tab), 0x0000, DEVICE_RAM },
    { &ram_file_ops, item_disp_tab, array_count(item_disp_tab), 0x0000, DEVICE_RAM },
    { &ram_file_ops, item_general_tab, array_count(item_general_tab), 0x0000, DEVICE_RAM },
    { &ram_file_ops, item_prepay_ram_tab, array_count(item_prepay_ram_tab), 0x0000, DEVICE_RAM },
    { &ram_file_ops, item_display_history_tab, array_count(item_display_history_tab), 0x0000, DEVICE_RAM },
};
const uint16 CODE partition_num = array_count(file_partitions);

