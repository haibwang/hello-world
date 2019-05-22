
#include "generator.h"
#include "data_table_gen.h"
#include <vcruntime.h>

struct cell_key_value_t             data_table_cell_title[] =
{
	{ "id",                          0 },
	{ "save_address",                0 },
	{ "len",                         0 },
	{ "same",                        0 },
	{ "data_format",                 0 },
	{ "notify_index",                0 },
	{ "ram_driver",                  0 },
	{ "enabled_same",                0 },
	{ "media_page_size",             0 },
	{ "enabled_check",               0 },
	{ "comment",                     0 },
};
char data_table_cell_title_num = sizeof(data_table_cell_title) / sizeof(data_table_cell_title[0]);

struct cell_key_value_t  format_table_cell_title[] =
{
	{ "format"    , 0 },
	{ "data_type" , 0 },
	{ "unit" ,     0 },
	{ "decimals",  0 },
	{ "index",     0 },
	{ "comment",   0 },
};
char format_table_cell_title_num = sizeof(format_table_cell_title) / sizeof(format_table_cell_title[0]);

struct cell_key_value_t  notify_tab_title[] =
{
	{ "notify"    , 0 },
	{ "index",     0 },
	{ "comment",   0 },
};
char notify_tab_title_num = sizeof(notify_tab_title) / sizeof(notify_tab_title[0]);

struct cell_key_value_t  partition_tab_title[] =
{
    { "ops"    ,    0 },
    { "items",      0 },
    { "itemNum",    0 },
    { "bak_size",   0 },
    { "attr",       0 },
};
char partition_tab_title_num = sizeof(partition_tab_title) / sizeof(partition_tab_title[0]);

struct sheet_ops_t                  sheet_ops[] =
{
#if 0
    { "item_para_calibration_tab", file_t_sheet_ops },
    { "item_para1_tab",             file_t_sheet_ops },
    { "item_para2_tab",            file_t_sheet_ops },
    { "item_para_power_off_tab",   file_t_sheet_ops },
    { "item_tariff_tab",           file_t_sheet_ops },
    { "item_history_tab",        file_t_sheet_ops },
    { "item_RamMap_tab",           file_t_sheet_ops },
    { "item_energy_powoff_save_tab",file_t_sheet_ops },
    { "item_energySave_tab",       file_t_sheet_ops },
    { "item_energy_tab",           file_t_sheet_ops },
    { "item_demand_tab",           file_t_sheet_ops },
    { "item_Instantaneous_tab",    file_t_sheet_ops },
    { "item_profile_log_tab",             file_t_sheet_ops },
    { "item_disp_tab",             file_t_sheet_ops },
    { "item_demandram_tab",          file_t_sheet_ops },
    { "item_char_device_tab",      file_t_sheet_ops },
    { "item_comm_tab",             file_t_sheet_ops },
    { "item_accumulation_demand_tab",      file_t_sheet_ops },
    { "item_demand_occuring_time_tab",      file_t_sheet_ops },
    { "item_general_tab",      file_t_sheet_ops },
    { "item_prepay_ram_tab",      file_t_sheet_ops },
    { "item_para_power_off_tab",      file_t_sheet_ops },
    { "item_event_log_tab",      file_t_sheet_ops },
    { "item_prepay_tab",      file_t_sheet_ops },
    { "item_display_history_tab", file_t_sheet_ops },

    { "file_partition_tab",        partition_t_sheet_ops },
	{ "file_format",               file_format_t_sheet_ops },
	{ "notify_tab",                notify_index_t_sheet_ops },
#endif

    { "file_t_sheet_ops"        ,   file_t_sheet_ops         },
    { "partition_t_sheet_ops"   ,   partition_t_sheet_ops    },
    { "file_format_t_sheet_ops" ,   file_format_t_sheet_ops  },
    { "notify_index_t_sheet_ops",   notify_index_t_sheet_ops },
    { "null",   NULL },
};

char sheet_ops_num = sizeof(sheet_ops) / sizeof(sheet_ops[0]);