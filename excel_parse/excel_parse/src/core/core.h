#pragma once

typedef struct _iobuf FILE;

int core_generate(wchar_t *xlsx_file, FILE *out_file, FILE *log_file,
	char *tem_filename, char *code_generator_name);
