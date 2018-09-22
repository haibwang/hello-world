

#include "def_type.h"
#include "stacklib.h"
#include <String.h>
#include <ctype.h>
#define ARRAY_COUNT(X) (sizeof(X)/sizeof(X[0]))

STACK *stack;

struct tken_operation_t
{
    uint8 tken;
    uint8(*function)(uint8 * buf, uint8 data, uint8* offset);
};

TResult init_stack(void)
{
    stack = stack_opr.creat(1024);
    if (stack)
    {
        return true;
    }
    return false;
}

uint8 push_stack(uint8 * buf, uint8 data, uint8* offset)
{
    return stack_opr.push(data);
}

uint8 compare(uint8 * buf, uint8 data, uint8* offset)
{
    uint8 temp;
    uint8 ret;
    uint8 priority[] = { '*','/','+','-' };
    uint8 index=0xff, index2=0xff;
    if (stack_opr.stack_top())
    {
        ret = stack_opr.get_top_data(&temp);
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
        if (index2 > 1 && index < 2)
        {
            ret = stack_opr.pop(buf+ *offset);
            (*offset)++;
            ret = stack_opr.push(data);
        }
        else
        {
          ret =  stack_opr.push(data);
        }
    }
    else
    {
        ret = stack_opr.push(data);
    }
    return ret;
}

uint8 pop_stack(uint8 * buf, uint8 data, uint8 *offset)
{
    uint8 temp = 0;
    uint8 index = 0;
    uint8 ret = 1;
    for (size_t i = 0; temp != '('; i++)
    {
        if (stack_opr.stack_top())
        {
            ret = stack_opr.pop(&temp);
            index = *offset;
            buf[index] = temp;
            (*offset)++;
        }
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


TResult turn_to_suffix_expression(String  infix_expression, char * suffix_expression)
{
    uint8 len;
    uint8 buf[255] = {0};
    uint8 index = 0;
    uint8 temp=0;
    uint8 ret=0;

    len = strlen(infix_expression) - 1;
    for (int i=0;i<len;i++)
    {
        if (isdigit(*infix_expression))
        {
            buf[index] = *infix_expression;
            index++;
        }
        else
        {
            for (int j=0;j< array_len;j++)
            {
                if (token_operate[j].tken == *infix_expression && token_operate[j].function)
                {
                    ret = token_operate[j].function(buf, *infix_expression, &index);
                    break;
                }
            }
        }
        infix_expression++;
    }
    
    if (ret == false)
    {
        memset(suffix_expression, '0', len);
        memset(suffix_expression+len, 0, 1);

        return 0;
    }
    memcpy(suffix_expression, buf, len);
    memset(suffix_expression + len, 0, 1);
    return true;
}








uint8 calculate(String infix_expression, char * suffix_expression)
{
    if (init_stack())
    {
        turn_to_suffix_expression(infix_expression, suffix_expression);
        stack_opr.clean();
    }
}








