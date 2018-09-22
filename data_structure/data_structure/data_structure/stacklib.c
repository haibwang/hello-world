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

struct stack_data_t *stack_data;

/************************************************************************/
/*  单栈 、循环栈 、共享空间栈                                              */
/************************************************************************/
struct stack_data_t * init(uint32 size)
{
    stack_data = (struct stack_data_t *)malloc(sizeof(struct stack_data_t));
    stack_data->stack_addr = (uint8 *)malloc(size);
    memset(stack_data->stack_addr,0, size);
    if (stack_data->stack_addr)
    {
        stack_data->top = 0;
        stack_data->stack_size = size;
        return stack_data;
    }
    return __NULL;
}

TResult push(uint8 data)
{
    if (stack_data->top < stack_data->stack_size)
    {
        stack_data->stack_addr[stack_data->top] = data;
        stack_data->top++;
        return true;
    }
    return false;
}

TResult pop(uint8 *data)
{
    if (stack_data->top > 0 && data)
    {
        stack_data->top--;
        *data = stack_data->stack_addr[stack_data->top];
        return true;
    }
    *data = 0;
    return false;
}

TResult clean(void)
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

uint32 get_stack_len(void)
{
    return stack_data->stack_size;
}

uint32 get_stack_free(void)
{
    return stack_data->stack_size - stack_data->top;
}

uint32 get_stack_top(void)
{
    return stack_data->top;
}

uint32 get_top_data(uint8 *data)
{
    *data = stack_data->stack_addr[stack_data->top];
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



