#pragma once

struct stack_t
{
    TResult(*init)(uint32 size);
    TResult(*push)(uint8 data);
    TResult(*pop)(uint8 *data);
    TResult(*clean)(void);
    uint32(*get_stack_len)(void);
    uint32(*get_stack_free)(void);
};

extern struct stack_t stack;
