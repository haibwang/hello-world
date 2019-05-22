#pragma once


/*前置声明*/
typedef struct _iobuf FILE;
typedef struct tagBookHandle * BookHandle;
typedef struct tagSheetHandle * SheetHandle;

#define TITLE_LEN 30

struct cell_key_value_t
{
	char  	                     key_name[TITLE_LEN]; /* 表格表头 */
	char                        *key_value;           /* 单元格值 */
};


struct sheet_ops_t
{
	char *ops_name;      /* 表格名 */
	char (*sheet_ops)(FILE *out_file,
		FILE *log_file,
		char *tem_filename,
		SheetHandle sheet,
		BookHandle book,
		char *sheet_name);  /* 表格操作函数 */
};