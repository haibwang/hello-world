#pragma once

struct stack_data_t
{
    void  *stack_addr;
    uint32 stack_size;
    uint8  top;
};

typedef struct stack_data_t STACK;

struct stack_t
{
	struct stack_data_t * (*creat)(uint32 size);
    TResult(*push)(struct stack_data_t *stack_data, void *data, uint8 len, uint8 data_type);
    TResult(*pop)(struct stack_data_t *stack_data, void *data, uint8 len, uint8 data_type);
    TResult(*clean)(struct stack_data_t *stack_data);
    uint32(*stack_len)(struct stack_data_t *stack_data);
    uint32(*stack_free)(struct stack_data_t *stack_data);
    uint32(*stack_top)(struct stack_data_t *stack_data);
    uint32(*get_top_data)(struct stack_data_t *stack_data, void *data, uint8 len, uint8 data_type);
};

extern struct stack_t stack_opr;


enum 
{
	UINT8_TYPE,
	UINT16_TYPE,
	UINT32_TYPE,
	UINT64_TYPE,
	INT8_TYPE,
	INT16_TYPE,
	INT32_TYPE,
	INT64_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
};













