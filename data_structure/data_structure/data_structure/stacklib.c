/**********************************************
** File name : stacklib.c
** Author    : haibowang
** Time      : 2018-9-20
** version   : 1.0
** Dscription:
***********************************************/

#include "def_type.h"
#include "stacklib.h"
#include <stdlib.h>
#include <string.h>

/************************************************************************
  单栈 、循环栈 、共享空间栈  


  本部分为 顺序存储单栈
/************************************************************************/
struct stack_data_t * init(uint32 size)
{
	struct stack_data_t *stack_data;

    stack_data = (struct stack_data_t *)malloc(sizeof(struct stack_data_t));
    stack_data->stack_addr = malloc(size);
    memset(stack_data->stack_addr,0, size);
    if (stack_data->stack_addr)
    {
        stack_data->top = 0;
        stack_data->stack_size = size;
        return stack_data;
    }
    return __NULL;
}

TResult push(struct stack_data_t *stack_data, void * data, uint8 len, uint8 data_tye)
{
	for (size_t i = 0; i < len+1; i++)
	{
		if (stack_data->top < stack_data->stack_size)
		{
			if (i == len)
			{
				*(((uint8 *)stack_data->stack_addr) + stack_data->top) = data_tye;
			}
			else
			{
				*(((uint8 *)stack_data->stack_addr) + stack_data->top) = *((uint8 *)data + i);
			}	
			stack_data->top++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

TResult pop(struct stack_data_t *stack_data, void *data, uint8 len, uint8 data_type)
{
    if (stack_data->top > 0 && data)
    {
        stack_data->top--;
        data_type = *((uint8 *)stack_data->stack_addr+stack_data->top);
		for (size_t i = 0; i < len; i++)
		{
			if (stack_data->top > 0 && data)
			{
				stack_data->top--;
				*((uint8 *)data+len-1-i) = *((uint8 *)stack_data->stack_addr + stack_data->top);
			}
			else
			{
				memset(data, 0, len + 1);
				return false;
			}
		}
    }
	
    return true;
}

TResult clean(struct stack_data_t *stack_data)
{
    if (stack_data->stack_addr)
    {
        free(stack_data->stack_addr);
        stack_data->top = 0;
        stack_data->stack_size = 0;
        return true;
    }
    return false;
}

uint32 get_stack_len(struct stack_data_t *stack_data )
{
    return stack_data->top;
}

uint32 get_stack_free(struct stack_data_t *stack_data)
{
    return stack_data->stack_size - stack_data->top;
}

uint32 get_stack_top(struct stack_data_t *stack_data)
{
    return stack_data->top;
}

uint32 get_top_data(struct stack_data_t *stack_data, void *data,uint8 len, uint8 data_type)
{
	uint8 index = 0;

	if (stack_data->top > 1)
	{
		data_type = *((uint8 *)stack_data->stack_addr + stack_data->top - 1);
	}
	for (size_t i = 0; i < len; i++)
	{
		index = stack_data->top-i-1;
		if (stack_data->top>len+1)
		{
			*((uint8 *)data+len-1-i) = *((uint8 *)stack_data->stack_addr + index - 1);
		}
	}
    
    return true;
}

struct stack_t stack_opr =
{
    init,
    push,
    pop,
    clean,
    get_stack_len,
    get_stack_free,
    get_stack_top,
    get_top_data,
};



