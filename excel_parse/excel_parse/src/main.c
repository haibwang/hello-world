#include <vcruntime.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdint.h>
#include "getopt.h"
#include "core.h"


#define LOG_ENABLE
#ifdef LOG_ENABLE
#define log(x)            do {  printf x; } while (0)
#define wlog(x)           do { wprintf x; } while (0)

#else
#define log(x)
#define wlog(x)
#endif
void color(const unsigned short textColor)
{
	if (textColor >= 0 && textColor <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void print_help(const char *codefile_name_array[])
{
	color(15);
	printf("%-10s:xlsx file name.\n","-f FILE");
	printf("%-10s:the template name.\n", "-t FILE");
	printf("%-10s:generate code file name,support options list as flow:\n", "-n FILE");
	color(14);
	for (int i=0; strcmp(codefile_name_array[i],"end")!=0; i++)
	{
		printf("%s:%-20s\n", "          ",codefile_name_array[i]);
	}
	color(7);
}

void get_filename(char *path, char *name)
{
    int i, j = 0;

    for (i = 0; path[i]; i++)
    {
        if (path[i] == '\\')
        {
            j = i;
        }
    }
    strcpy_s(name, 30, &path[j+1]);
}

int main(int argc, const char **argv) {

	FILE                            *log_file;
	FILE                            *out_file;
	char                            *code_generator_path = NULL;
    char                            code_generator_name[30];
	char							*log_filename  = ".\\log.txt";
	char							*tem_filename = NULL;
	char							*char_xl_filename;
	wchar_t							*xlsx_filename = NULL;
	int                             out_file_error;
	int                             log_file_error;
	int                             optc;
    char                            result;//处理结果判断

    result = 0;

	const char *support_code_gen[] =
	{
		"data_cfg.c",

		"end"
	};
//#define  TEST
#ifndef TEST
	if (argc < 2)
	{
		color(14);
		printf("input argument -h or -H for help\n");
		color(7);
		system("pause");
		return 0;
	}
	while ((optc = getopt(argc, argv,"f:F:t:T:n:N:hH"))!=-1)
	{
		switch (optc)
		{
		case 'F':
		case 'f':
			char_xl_filename = optarg;
			size_t len = strlen(char_xl_filename) + 1;
			size_t converted = 0;
			xlsx_filename = (wchar_t*)malloc(len * sizeof(wchar_t));
			mbstowcs_s(&converted, xlsx_filename, len, char_xl_filename, _TRUNCATE);
			wlog((L"f: %ls\n", xlsx_filename));
			break;
		case 'T':
		case 't':
			tem_filename = optarg;
			log(("t: %s\n", tem_filename));
			break;
		case 'N':
		case 'n':
            code_generator_path = optarg;
			log(("n: %s\n", code_generator_path));
			break;
		case 'H':
		case 'h':
			print_help(support_code_gen);
			return 0;
		default:
			break;
		}
	}
#else
	char_xl_filename = "D:\\VSPro\\excel_parse\\x64\\Release\\data_table.xlsm";
	size_t len = strlen(char_xl_filename) + 1;
	size_t converted = 0;
	xlsx_filename = (wchar_t*)malloc(len * sizeof(wchar_t));
	mbstowcs_s(&converted, xlsx_filename, len, char_xl_filename, _TRUNCATE);
    code_generator_path = ".\\data_cfg.c";
	tem_filename = "D:\\VSPro\\excel_parse\\x64\\Release\\data_table.tmpl";
	log(("n: %s\n", code_generator_path));
	wlog((L"f: %s\n", xlsx_filename));
	log(("t: %s\n", tem_filename));
#endif
	if (!xlsx_filename || !code_generator_path || !tem_filename)
	{
		log(("illegal arguments\n"));
		return 1;
	}
	
	out_file_error = fopen_s(&out_file, code_generator_path, "w+");
	log_file_error = fopen_s(&log_file, log_filename, "w+");

	if (out_file_error != 0 || log_file_error != 0 )
	{ 
		perror("open file:");
		system("pause");
		exit(1);
	}
    get_filename(code_generator_path, code_generator_name);
	result = core_generate(xlsx_filename, out_file, log_file, tem_filename, code_generator_name);

	free(xlsx_filename);
	fclose(out_file);
	fclose(log_file);

    if (result)
    {
        system(log_filename);
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
	return 0;
}
 