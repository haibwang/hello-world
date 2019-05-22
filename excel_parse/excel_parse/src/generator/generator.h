#pragma once


/*ǰ������*/
typedef struct _iobuf FILE;
typedef struct tagBookHandle * BookHandle;
typedef struct tagSheetHandle * SheetHandle;

#define TITLE_LEN 30

struct cell_key_value_t
{
	char  	                     key_name[TITLE_LEN]; /* ����ͷ */
	char                        *key_value;           /* ��Ԫ��ֵ */
};


struct sheet_ops_t
{
	char *ops_name;      /* ����� */
	char (*sheet_ops)(FILE *out_file,
		FILE *log_file,
		char *tem_filename,
		SheetHandle sheet,
		BookHandle book,
		char *sheet_name);  /* ���������� */
};