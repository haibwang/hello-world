#include <stdio.h>
#include <stdlib.h>
#include <vcruntime.h>
#include <string.h>
#include "libxl.h"
#include "cfg.h"

#define NO_THIS_GENERATOR 0xFF

unsigned int   get_generator_index(char *code_generator_name)
{
	for (int i=0; i<code_generator_num; i++)
	{
		if (!strcmp(code_generator[i]->code_generator_name, code_generator_name))
		{
			return i;
		}
	}
	return NO_THIS_GENERATOR;
}

//返回 0 成功
char process_excel(wchar_t *xlsx_file, FILE *out_file, FILE *log_file,
	          char *tem_filename, unsigned int code_generator_index)
{
	BookHandle                      book = NULL;
	SheetHandle                     sheet = NULL;
	unsigned int                    sheet_num;
    char                            flag;//返回结果，0成功，有1失败

    flag = 0;
	book = xlCreateXMLBook();
	xlBookSetKey(book, L"GCCG", L"windows-282123090cc0e6036db16b60a1o3p0h9");   /*注册*/

	if (book)
	{
		if (xlBookLoad(book, xlsx_file))
		{
			sheet_num = xlBookSheetCount(book);

			for (unsigned int i = 0; i < sheet_num; i++)
			{
				sheet = xlBookGetSheet(book, i);
				if (sheet)
				{
                    flag |= code_generator[code_generator_index]->code_generate(out_file, log_file, tem_filename, sheet, book);
				}
				else
				{
					fprintf(log_file, "get the %d sheet filed\n", i);
                    flag = 1;
				}
			}
			xlBookRelease(book);
		}
	}
    return flag;
}

int core_generate(wchar_t *xlsx_file, FILE *out_file, FILE *log_file, 
	             char *tem_filename, char *code_generator_name)
{

	unsigned int  code_generator_index = 0xFF;

	code_generator_index = get_generator_index(code_generator_name);
	if (NO_THIS_GENERATOR == code_generator_index)
	{
		fprintf(log_file, "sorry, %s : don't have a corresponding code generator\n", code_generator_name);
		return (1);
	}

    return process_excel(xlsx_file, out_file, log_file, tem_filename, code_generator_index);
	
}