#pragma once


/*Ç°ÖÃÉùÃ÷*/
typedef struct _iobuf FILE;
typedef struct tagBookHandle * BookHandle;
typedef struct tagSheetHandle * SheetHandle;



extern struct cell_key_value_t             data_table_cell_title[];
extern struct cell_key_value_t             format_table_cell_title[];
extern struct cell_key_value_t             notify_tab_title[];
extern struct cell_key_value_t             partition_tab_title[];
extern struct sheet_ops_t                  sheet_ops[];


extern char   sheet_ops_num;
extern char   data_table_cell_title_num;
extern char   format_table_cell_title_num;
extern char   notify_tab_title_num;
extern char partition_tab_title_num;

extern void file_t_sheet_ops(FILE *out_file, FILE *log_file,
	char *tem_filename, SheetHandle sheet,
	BookHandle book, char *sheet_name);
extern void file_format_t_sheet_ops(FILE *out_file, FILE *log_file,
	char *tem_filename, SheetHandle sheet,
	BookHandle book, char *sheet_name);
extern void notify_index_t_sheet_ops(FILE *out_file, FILE *log_file,
	char *tem_filename, SheetHandle sheet,
	BookHandle book, char *sheet_name);
extern void partition_t_sheet_ops(FILE *out_file, FILE *log_file,
    char *tem_filename, SheetHandle sheet,
    BookHandle book, char *sheet_name);