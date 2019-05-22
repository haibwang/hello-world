#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <corecrt_wstring.h>
#include "libxl.h"
#include "ctemplate.h"

#include "generator.h"
#include "data_table_gen.h"
#include "cfg.h"


#define EN_SAME 7
#define SAME    3
#define CHECK	9


char file_t_sheet_ops(FILE *out_file, FILE *log_file,
	                  char *tem_filename, SheetHandle sheet,
	                  BookHandle book, char *sheet_name)
{

	TMPL_varlist                    *mylist = NULL;       /* declare the variable list */
	TMPL_varlist                    *mainlist = NULL;     /* add the loop variable */
	TMPL_loop                       *loop = NULL;

	int                             sheet_row_num;
	const wchar_t                   *temp = NULL;
    int                             temp2 = 0xFFFFFFFF;

    char flag = 0;

	sheet_row_num = xlSheetLastRow(sheet);

	/* 增量i,根据同类项使能的情况，跳过同类项部分 */
	for (int i = 1; i < sheet_row_num;i++)
		//i += (0x01 & (int)xlSheetReadNum(sheet, i, EN_SAME, NULL)) ?  (int)xlSheetReadNum(sheet, i, SAME, NULL) :  1)
	{
		
        temp = xlSheetReadStr(sheet, i, 0, NULL); //用于判断第一列为空时，不生成
        temp2 = xlSheetReadNum(sheet, i, 2, NULL); //用于判断长度为0时，不生成
		for (int j = 0; j < data_table_cell_title_num && temp && temp2!=0; j++)
		{
			//if (9 == j)
			//{
			//	/* 如果同类项使能了，检验位要看同类项最后一个数据的校验位 */
			//	temp = (0x01 & (int)xlSheetReadNum(sheet, i, EN_SAME, NULL)) ?
			//		xlSheetReadStr(sheet, i + (int)xlSheetReadNum(sheet, i, SAME, NULL) - 1, CHECK, NULL) :
			//		xlSheetReadStr(sheet, i, CHECK, NULL);
			//}
			//else
			{
				temp = xlSheetReadStr(sheet, i, j, NULL);
			}

			if (temp)
			{
				/* 如果读取的值不为空，则转换为款字符 */
				data_table_cell_title[j].key_value = (char *)malloc(2 * wcslen(temp) + 1);
				if (data_table_cell_title[j].key_value)
				{
					/* 款字符转换为窄字符 */
					wcstombs(data_table_cell_title[j].key_value, temp, 2 * wcslen(temp) + 1);
				}
			}
			else
			{
				data_table_cell_title[j].key_value = " ";
				fprintf(log_file, "%-30s ::行%d 列%d :%s\n", sheet_name, i + 1, j + 1, xlBookErrorMessage(book));
                flag = 1;
			}
		}
		  
		/* load the variable list with TMPL_add_var()  */
		mylist = TMPL_add_var( 0,
				data_table_cell_title[0].key_name, data_table_cell_title[0].key_value,
				data_table_cell_title[1].key_name, data_table_cell_title[1].key_value,
				data_table_cell_title[2].key_name, data_table_cell_title[2].key_value,
				data_table_cell_title[3].key_name, data_table_cell_title[3].key_value,
				data_table_cell_title[4].key_name, data_table_cell_title[4].key_value,
				data_table_cell_title[5].key_name, data_table_cell_title[5].key_value,
				data_table_cell_title[6].key_name, data_table_cell_title[6].key_value,
				data_table_cell_title[7].key_name, data_table_cell_title[7].key_value,
				data_table_cell_title[8].key_name, data_table_cell_title[8].key_value,
				data_table_cell_title[9].key_name, data_table_cell_title[9].key_value,
				data_table_cell_title[10].key_name, data_table_cell_title[10].key_value,
				0);

		loop = TMPL_add_varlist(loop, mylist);
		for (int i = 0; i < 11; i++)
		{
			if (data_table_cell_title[i].key_value &&
				strcmp(data_table_cell_title[i].key_value, " ") != 0)
			{
				free(data_table_cell_title[i].key_value);
				data_table_cell_title[i].key_value = NULL;
			}
		}
	}	
	mainlist = TMPL_add_var(0, "file_t_tab_name", sheet_name,0);
	mainlist = TMPL_add_var(mainlist, "file_t", "file",0);
	mainlist = TMPL_add_loop(mainlist, "file_loop", loop);

	/* output the template and free variable list memory */
	TMPL_write(tem_filename, 0, 0, mainlist, out_file, log_file);
	TMPL_free_varlist(mainlist);

    return flag;
}

char file_format_t_sheet_ops(FILE *out_file, FILE *log_file,
	char *tem_filename, SheetHandle sheet, BookHandle book, char *sheet_name)
{
	TMPL_varlist                    *mylist = NULL;       /* declare the variable list */
	TMPL_varlist                    *mainlist = NULL;     /* add the loop variable */
	TMPL_loop                       *loop = NULL;

	int                             sheet_row_num;
	const wchar_t                   *temp = NULL;
    char flag = 0;

	sheet_row_num = xlSheetLastRow(sheet);

	for (int i = 1; i < sheet_row_num; i++)
	{
        temp = xlSheetReadStr(sheet, i, 0, NULL); //用于判断第一列为空时，不生成

		for (int j = 0; j < format_table_cell_title_num && temp; j++)
		{
			temp = xlSheetReadStr(sheet, i, j, NULL);
			if (temp)
			{
				format_table_cell_title[j].key_value = (char *)malloc(2 * wcslen(temp) + 1);
				if (format_table_cell_title[j].key_value)
				{
					/* 款字符转换为窄字符 */
					wcstombs(format_table_cell_title[j].key_value, temp, 2 * wcslen(temp) + 1);
				}
			}
			else
			{
				format_table_cell_title[j].key_value = " ";
				fprintf(log_file, "%-30s ::行%d 列%d :%s\n", sheet_name, i+1, j+1, xlBookErrorMessage(book));
                flag = 1;
			}
		}

		/* load the variable list with TMPL_add_var()  */
		mylist = TMPL_add_var(0,
			format_table_cell_title[0].key_name, format_table_cell_title[0].key_value,
			format_table_cell_title[1].key_name, format_table_cell_title[1].key_value,
			format_table_cell_title[2].key_name, format_table_cell_title[2].key_value,
			format_table_cell_title[3].key_name, format_table_cell_title[3].key_value,
			format_table_cell_title[4].key_name, format_table_cell_title[4].key_value,
			format_table_cell_title[5].key_name, format_table_cell_title[5].key_value,
			0);

		loop = TMPL_add_varlist(loop, mylist);
		for (int i = 0; i < format_table_cell_title_num; i++)
		{
			if (format_table_cell_title[i].key_value &&
				strcmp(format_table_cell_title[i].key_value, " ") != 0)
			{
				free(format_table_cell_title[i].key_value);
				format_table_cell_title[i].key_value = NULL;
			}
		}
	}
	mainlist = TMPL_add_var(0, "file_format_tab_name", sheet_name,0);
	mainlist = TMPL_add_var(mainlist, "format_t", "format",0);
	mainlist = TMPL_add_loop(mainlist, "format_loop", loop);
	
	/* output the template and free variable list memory */
	TMPL_write(tem_filename, 0, 0, mainlist, out_file, log_file);
	TMPL_free_varlist(mainlist);

    return flag;
}

char notify_index_t_sheet_ops(FILE *out_file, FILE *log_file,
	char *tem_filename, SheetHandle sheet, BookHandle book, char *sheet_name)
{
	TMPL_varlist                    *mylist = NULL;       /* declare the variable list */
	TMPL_varlist                    *mainlist = NULL;     /* add the loop variable */
	TMPL_loop                       *loop = NULL;

	int                             sheet_row_num;
	const wchar_t                   *temp = NULL;
    char flag = 0;

	sheet_row_num = xlSheetLastRow(sheet);

	for (int i = 1; i < sheet_row_num; i++)
	{

        temp = xlSheetReadStr(sheet, i, 0, NULL);//用于判断第一列为空时，不生成

		for (int j = 0; j < notify_tab_title_num && temp; j++)
		{
			temp = xlSheetReadStr(sheet, i, j, NULL);
			if (temp)
			{
				notify_tab_title[j].key_value = (char *)malloc(2 * wcslen(temp) + 1);
				if (notify_tab_title[j].key_value)
				{
					/* 款字符转换为窄字符 */
					wcstombs(notify_tab_title[j].key_value, temp, 2 * wcslen(temp) + 1);
				}
			}
			else
			{
				notify_tab_title[j].key_value = " ";
				fprintf(log_file, "%-30s ::行%d 列%d :%s\n", sheet_name, i + 1, j + 1, xlBookErrorMessage(book));
                flag = 1;
			}
		}

		/* load the variable list with TMPL_add_var()  */
		mylist = TMPL_add_var(0,
			notify_tab_title[0].key_name, notify_tab_title[0].key_value,
			notify_tab_title[1].key_name, notify_tab_title[1].key_value,
			notify_tab_title[2].key_name, notify_tab_title[2].key_value,
			0);

		loop = TMPL_add_varlist(loop, mylist);
		for (int i = 0; i < notify_tab_title_num; i++)
		{
			if (notify_tab_title[i].key_value &&
				strcmp(notify_tab_title[i].key_value, " ") != 0)
			{
				free(notify_tab_title[i].key_value);
				notify_tab_title[i].key_value = NULL;
			}
		}
	}
	mainlist = TMPL_add_var(0, "notify_tab_name", sheet_name, 0);
	mainlist = TMPL_add_var(mainlist, "notify_index_t", "notify_index", 0);
	mainlist = TMPL_add_loop(mainlist, "notify_index_loop", loop);

	/* output the template and free variable list memory */
	TMPL_write(tem_filename, 0, 0, mainlist, out_file, log_file);
	TMPL_free_varlist(mainlist);
    return flag;
}


void partition_t_sheet_ops(FILE *out_file, FILE *log_file,
    char *tem_filename, SheetHandle sheet, BookHandle book, char *sheet_name)
{
    TMPL_varlist                    *mylist = NULL;       /* declare the variable list */
    TMPL_varlist                    *mainlist = NULL;     /* add the loop variable */
    TMPL_loop                       *loop = NULL;

    int                             sheet_row_num;
    const wchar_t                   *temp = NULL;
    char flag = 0;

    sheet_row_num = xlSheetLastRow(sheet);

    for (int i = 1; i < sheet_row_num; i++)
    {

        temp = xlSheetReadStr(sheet, i, 0, NULL); //用于判断第一列为空时，不生成

        for (int j = 0; j < partition_tab_title_num && temp; j++)
        {
            temp = xlSheetReadStr(sheet, i, j, NULL);
            if (temp)
            {
                partition_tab_title[j].key_value = (char *)malloc(2 * wcslen(temp) + 1);
                if (partition_tab_title[j].key_value)
                {
                    /* 款字符转换为窄字符 */
                    wcstombs(partition_tab_title[j].key_value, temp, 2 * wcslen(temp) + 1);
                }
            }
            else
            {
                partition_tab_title[j].key_value = " ";
                fprintf(log_file, "%-30s ::行%d 列%d :%s\n", sheet_name, i + 1, j + 1, xlBookErrorMessage(book));
                flag = 1;
            }
        }

        /* load the variable list with TMPL_add_var()  */
        mylist = TMPL_add_var(0,
            partition_tab_title[0].key_name, partition_tab_title[0].key_value,
            partition_tab_title[1].key_name, partition_tab_title[1].key_value,
            partition_tab_title[2].key_name, partition_tab_title[2].key_value,
            partition_tab_title[3].key_name, partition_tab_title[3].key_value,
            partition_tab_title[4].key_name, partition_tab_title[4].key_value,
            0);

        loop = TMPL_add_varlist(loop, mylist);
        for (int i = 0; i < partition_tab_title_num; i++)
        {
            if (partition_tab_title[i].key_value &&
                strcmp(partition_tab_title[i].key_value, " ") != 0)
            {
                free(partition_tab_title[i].key_value);
                partition_tab_title[i].key_value = NULL;
            }
        }
    }
    mainlist = TMPL_add_var(0, "partition_tab_name", sheet_name, 0);
    mainlist = TMPL_add_var(mainlist, "partition_t", "file_partitions", 0);
    mainlist = TMPL_add_loop(mainlist, "partition_loop", loop);

    /* output the template and free variable list memory */
    TMPL_write(tem_filename, 0, 0, mainlist, out_file, log_file);
    TMPL_free_varlist(mainlist);

    return flag;
}



int data_table_code_generate(FILE *out_file, FILE *log_file,
    char *tem_filename, SheetHandle sheet, BookHandle book)
{
    const wchar_t                   *sheet_name_temp = NULL;
    const wchar_t                   *cfg_name_temp = NULL;
    const wchar_t                   *ops_name_temp = NULL;
    char                            *sheet_name = NULL;
    char                            *ops_name = NULL;
    char                            *cfg_name = NULL;

    SheetHandle                     cfg_sheet = NULL;
    unsigned int                    cfg_num;

    setlocale(LC_ALL, "chs");  /*设置本地语言*/

    sheet_name_temp = xlSheetName(sheet);
    sheet_name = (char *)malloc(2 * wcslen(sheet_name_temp) + 1);
    wcstombs(sheet_name, sheet_name_temp, 2 * wcslen(sheet_name_temp) + 1);

    cfg_sheet = xlBookGetSheet(book, 0);
    cfg_num = xlSheetLastRow(cfg_sheet);


    for (int j = 1; j < cfg_num; j++)
    {
        cfg_name_temp = xlSheetReadStr(cfg_sheet, j, 0, NULL);
        cfg_name = (char *)malloc(2 * wcslen(cfg_name_temp) + 1);
        wcstombs(cfg_name, cfg_name_temp, 2 * wcslen(cfg_name_temp) + 1);

        if (!strcmp(cfg_name, sheet_name))
        {
            ops_name_temp = xlSheetReadStr(cfg_sheet, j, 1, NULL);
            ops_name = (char *)malloc(2 * wcslen(ops_name_temp) + 1);
            wcstombs(ops_name, ops_name_temp, 2 * wcslen(ops_name_temp) + 1);
            for (int i = 0; i < sheet_ops_num; i++)
            {
                if (!strcmp(sheet_ops[i].ops_name, ops_name))
                {
                    if (sheet_ops[i].sheet_ops)
                    {
                        return sheet_ops[i].sheet_ops(out_file, log_file, tem_filename, sheet, book, sheet_name);
                    }
                    return 0;
                }
            }
            /* 没有相应表格的处理函数，退出 */
            fprintf(log_file, "%-30s ::this sheet don't have any operate fuction\n", sheet_name);
            return 1;
        }
    }

    
    /* 没有相应表格的处理函数，退出 */
    fprintf(log_file, "%-30s ::this sheet don't take handle\n", sheet_name);
    if (cfg_name)
    {
        free(cfg_name);
    }
    if (sheet_name)
    {
        free(sheet_name);
    }
    if (ops_name)
    {
        free(ops_name);
    }
    return 1;
}

struct code_generator_interface_t data_table_code_generator =
{
	 "data_cfg.c",
	 data_table_code_generate 
};   