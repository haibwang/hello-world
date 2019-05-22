#include "cfg.h"


extern struct code_generator_interface_t data_table_code_generator;

struct code_generator_interface_t *code_generator[] =
{
	&data_table_code_generator
};

int code_generator_num = sizeof(code_generator) / sizeof(code_generator[0]);