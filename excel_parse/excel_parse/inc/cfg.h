#pragma once

/*Ç°ÖÃÉùÃ÷*/
typedef struct _iobuf FILE;
typedef struct tagBookHandle * BookHandle;
typedef struct tagSheetHandle * SheetHandle;

struct code_generator_interface_t
{
	char *code_generator_name;
	char (*code_generate)(FILE *out_file, FILE *log_file, char *tem_filename, SheetHandle sheet, BookHandle book);
};

extern struct code_generator_interface_t *code_generator[];
extern int    code_generator_num;



