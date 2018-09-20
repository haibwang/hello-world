/**********************************************
** File name : stacklib.c
** Author    : haibowang
** Time      : 2018-9-20
** version   : 1.0
** Dscription:
***********************************************/

#include "def_type.h"
#include <stdlib.h>
#include <string.h>


struct stack_data_t
{
    uint8 * stack_addr;
    uint8 top;
    uint32 stack_size;
};

struct stack_data_t stack_data;


/************************************************************************/
/*  单栈 、循环栈 、共享空间栈                                              */
/************************************************************************/
TResult init(uint32 size)
{
    stack_data.stack_addr = (uint8 *)malloc(size);
    memset(stack_data.stack_addr,0, size);
    if (stack_data.stack_addr)
    {
        stack_data.top = 0;
        stack_data.stack_size = size;
        return true;
    }
    return false;
}

TResult push(uint8 data)
{
    if (stack_data.top < stack_data.stack_size)
    {
        stack_data.stack_addr[stack_data.top] = data;
        stack_data.top++;
        return true;
    }
    return false;
}

TResult pop(uint8 *data)
{
    if (stack_data.top > 0 && data)
    {
        stack_data.top--;
        *data = stack_data.stack_addr[stack_data.top];     
        return true;
    }
    *data = 0;
    return false;
}

TResult clean(void)
{
    if (stack_data.stack_addr)
    {
        free(stack_data.stack_addr);
        stack_data.top = 0;
        stack_data.stack_size = 0;
        return true;
    }
    return false;
}

uint32 get_stack_len(void)
{
    return stack_data.stack_size;
}

uint32 get_stack_free(void)
{
    return stack_data.stack_size - stack_data.top;
}




struct stack_t
{
    TResult (*init)(uint32 size);
    TResult (*push)(uint8 data);
    TResult (*pop)(uint8 *data);
    TResult (*clean)(void);
    uint32  (*get_stack_len)(void);
    uint32  (*get_stack_free)(void);
};

struct stack_t stack =
{
    init,
    push,
    pop,
    clean,
    get_stack_len,
    get_stack_free,
};



