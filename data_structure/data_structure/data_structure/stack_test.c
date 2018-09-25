#include "def_type.h"
#include "stacklib.h"


int test_stack(void)
{
	STACK * stack_add = __NULL;
	int32 a = -100;
	float b = 5.5;
	int32 c = 0;

	uint8 data_type;

	data_type = (uint8)INT32_TYPE;

	stack_add = stack_opr.creat(1024);
	stack_opr.push(stack_add, (void *)&a, sizeof(int32), data_type);
	stack_opr.push(stack_add, (void *)&b, sizeof(float), data_type);

	stack_opr.pop(stack_add, (void *)&b, sizeof(int32), data_type);
	stack_opr.pop(stack_add, (void *)&a, sizeof(int32), data_type);

	c = (int32)b;

	return 0;
}