#pragma once

struct stack_data_t
{
    uint8  *stack_addr;
    uint32 stack_size;
    uint8  top;
};

typedef struct stack_data_t STACK;

struct stack_t
{
    TResult(*creat)(uint32 size);
    TResult(*push)(uint8 data);
    TResult(*pop)(uint8 *data);
    TResult(*clean)(void);
    uint32(*stack_len)(void);
    uint32(*stack_free)(void);
    uint32(*stack_top)(void);
    uint32(*get_top_data)(uint8 *data);
};

extern struct stack_t stack_opr;


