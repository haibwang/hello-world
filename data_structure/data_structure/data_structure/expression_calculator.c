

#include "def_type.h"
#include "stacklib.h"
#include <String.h>
#include <ctype.h>
#include <stdlib.h>
#include "calclib.h"


struct tken_operation_t
{
    uint8 tken;
    uint8(*function)(STACK *stack, uint8 * buf, uint8 data, uint8* offset);
};

STACK * init_stack()
{
    return stack_opr.creat(1024);
}

uint8 push_stack(STACK *stack, uint8 * buf, uint8 data, uint8* offset)
{
	if (!stack)
	{
		return 0;
	}
    return stack_opr.push(stack, (void *)&data, 1, UINT8_TYPE);
}

uint8 pop_stack(STACK *stack, uint8 * buf, uint8 data, uint8 *offset)
{
	uint8 temp = 0;
	uint8 index = 0;
	uint8 ret = 1;
	uint8 data_type=0;

	if (!stack)
	{
		return 0;
	}

	for (size_t i = 0; temp != '('&&stack_opr.stack_top(stack); i++)
	{
		if (stack_opr.stack_top(stack))
		{
			ret = stack_opr.pop(stack, (void *)&temp, 1, data_type);
			if (temp != '(')
			{
				index = *offset;
				buf[index] = temp;
				(*offset)++;
			}
		}
	}

	return ret;
}

uint8 compare(STACK *stack, uint8 * buf, uint8 data, uint8* offset)
{
    uint8 temp;
    uint8 ret;
    uint8 priority[] = { '*','/','+','-' };
    uint8 index=0xff, index2=0xff;
	uint8 data_type=0;

	if (!stack)
	{
		return 0;
	}

    if (stack_opr.stack_top(stack))
    {
        ret = stack_opr.get_top_data(stack, (void *)&temp, 1, data_type);
        for (size_t i = 0; i < 4 && (index==0xff || index2==0xff); i++)
        {
            if (temp == priority[i])
            {
                index = i;
            }
            if (data == priority[i])
            {
                index2 = i;
            }   
        }
        if (index2 > 1 )
        {
			if ('(' != temp)
			{
				if (')' != data && index > 1)
				{
					ret = stack_opr.pop(stack, (void *)((uint8 *)buf+*offset), 1, UINT8_TYPE);
					(*offset)++;
				}
				else
				{
					pop_stack(stack, buf, 0, offset);
				}
			}
            ret = stack_opr.push(stack, (void *)&data, 1, UINT8_TYPE);
        }
        else
        {
          ret =  stack_opr.push(stack, (void *)&data, 1, UINT8_TYPE);
        }
    }
    else
    {
        ret = stack_opr.push(stack, (void *)&data, 1, UINT8_TYPE);
    }
    return ret;
}

const struct tken_operation_t token_operate[] =
{
    { '(', push_stack },
    { '*', compare },
    { '/', compare },
    { '+', compare },
    { '-', compare },
    { ')', pop_stack },
};

uint8 array_len = ARRAY_COUNT(token_operate);


TResult turn_to_suffix_expression(STACK *stack,uint8 *num_bits, String  infix_expression, char * suffix_expression)
{
    uint8 len;
    uint8 buf[255] = {0};
	uint8 ati[255] = { 0 };
	uint8 index = 0;
    uint8 temp=0;
    uint8 ret=0;
	uint8 z = 0;
	int i = 0;
	uint8 bit_index = 0;

	if (stack)
	{

		len = strlen(infix_expression);
		for (i = 0; i < len; i++)
		{
			if (*(infix_expression + i)>255 || *(infix_expression + i) < 0)
			{
				ret = 0;
				break;
			}
			if (' ' != *(infix_expression + i))
			{
				if (isdigit(*(infix_expression + i))||'.'==*(infix_expression+i))
				{
					z = 0;
					while (isdigit(*(infix_expression + i)) || '.' == *(infix_expression + i))
					{
						//ati[z] = *(infix_expression + i);
						buf[index] = *(infix_expression + i);
						index++;
						i++;
						z++;
					}
					buf[index] = ' ';
					index++;
					i--;
					//ati[z] = 'c';
					num_bits[bit_index++] = z;
				}
				else
				{
					for (int j = 0; j < array_len; j++)
					{
						if (token_operate[j].tken == *(infix_expression + i) && token_operate[j].function)
						{
							ret = token_operate[j].function(stack, buf, *(infix_expression + i), &index);	
							break;
						}
					}
				}
			}
		}
	}
    if (ret == false)
    {
        memset(suffix_expression, '0', len);
        memset(suffix_expression+len, 0, 1);

        return 0;
    }
	pop_stack(stack, buf, *(infix_expression + i), &index);
    memcpy(suffix_expression, buf, index);
    memset(suffix_expression + index, 0, 1);
    return true;
}



///////////////////////////////////////////////////////////////////////////
double muitil_opr(double num1, double num2)
{
	return num1 * num2;
}

double add_opr(double num1, double num2)
{
	return num1 + num2;
}

double sub_opr(double num1, double num2)
{
	return num1 - num2;
}


double divide_opr(double num1, double num2)
{
	if (num2 != 0)
	{
		return num1 / num2;
	}
	return 0;
}

struct calculate_mython_t
{
	char operation;
	double (*operate)(double num1, double num2);
};

struct calculate_mython_t calculate_mython[]=
{
	{ '*', muitil_opr,},
	{'+',  add_opr},
	{'-',  sub_opr},
	{'/',  divide_opr}
};
uint8 operation_num = ARRAY_COUNT(calculate_mython);

double calculate_value(STACK *stack_num, uint8 *num_bits, STACK *stack, const char* expression)
{
	uint8 buf[255] = {0};
	uint8 len;
	uint8 z = 0;
	uint8 index = 0;
	uint8 ret = 0;
	uint8 len_operation;
	double calc_value = 0;
	size_t k = 0;
	double num1 = 0;
	double num2 = 0;
	char operation;
	double value;
	uint8 temp;
	uint8 ati[255] = { 0 };
	uint8 index_num=0;
	uint8 data_type=0;
	double aa = 0;

	if (!(stack_num && num_bits && stack))
	{
		return 0;
	}

	len = strlen(expression);

	for (size_t i = 0; i < len; i++)
	{
		if (' ' != *(expression + i))
		{
			if (!(isdigit(*(expression + i))||'.'==*(expression+i)))
			{

				//for (size_t i = 0; ; i++)
				{
					stack_opr.pop(stack_num, (void *)&num2, sizeof(num2), data_type);
					stack_opr.pop(stack_num, (void *)&num1, sizeof(num1), data_type);
					//stack_opr.pop(stack, &operation);
					operation = *(expression + i);

					for (k = 0; k < operation_num; k++)
					{
						if (calculate_mython[k].operation == operation && calculate_mython[k].operate)
						{
							value = calculate_mython[k].operate((double)num1, (double)num2);
							stack_opr.push(stack_num, (void *)&value, sizeof(value), DOUBLE_TYPE);
							k = 0xff;
							break;
						}
					}
					if (0xff != k)
					{
						return 0;
					}
				}
			}
			else
			{
				z = 0;
				while (num_bits[index_num] > 0)
				{
					ati[z] = *(expression + i);
					i++;
					z++;
					num_bits[index_num]--;
				}
				index_num++;
				i--;
				ati[z] = 'c';
				aa = atof(ati);
				ret = stack_opr.push(stack_num, (void *)&aa, sizeof(double), DOUBLE_TYPE);
			}
		}
	}

	
	ret = stack_opr.pop(stack_num, (void *)&calc_value, sizeof(calc_value),data_type);
	if (!ret)
	{
		return 0;
	}
	return calc_value;
}



double calculate(String infix_expression, char * suffix_expression)
{
	double  value;
	STACK *stack=__NULL;
	STACK *stack_num = __NULL;
	STACK *stack_num2 = __NULL;

	stack =  init_stack();
	stack_num = init_stack();
	stack_num2 = init_stack();
	uint8 num_bits[255] = { 0 };

    if (stack && stack_num)
    {
        turn_to_suffix_expression(stack, num_bits, infix_expression, suffix_expression);
		
		value = calculate_value(stack_num, num_bits, stack, suffix_expression);
        stack_opr.clean(stack);
		stack_opr.clean(stack_num);

		return value;
    }

	return 0;
}








