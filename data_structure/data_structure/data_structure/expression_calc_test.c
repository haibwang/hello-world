/**********************************************
** File name : test.c 
** Author    : haibowang
** Time      : 2018-9-20
** version   : 1.0
** Dscription: uint test
***********************************************/

#include "def_type.h"
#include <stdio.h>
#include "stacklib.h"
#include "calclib.h"
#include <assert.h> 
#include "expression_calculator.h"

struct gain_expect_t 
{
	String gain_expression;
	String expect_expression;
	double expect_value;
};

struct gain_expect_t gain_expect[] =
{
	{ "9+(3-1)*3+10/2",           "931-3*+102/+",        20 },
	{ "3-2+1+4-9",                "32-1+4+9-"   ,        -3 },
	{ "3-(2+1)+(4-9)" ,           "321+-49-+"      ,     -5 },
	{ "3.0-(2+1.0)+(4-9)" ,       "3.021.0+-49-+"      , -5 },
	{ "3.5-(2+1.0)+(4-9.5)" ,     "3.521.0+-49.5-+"    , -5 },
	{ "3-(2+1-2+5+8)+(4-9)",      "321+2-5+8+-49-+"   , -16 },
	{ "3-(2+1-2*5+8)+(4-9)",      "321+25*-8+-49-+"    , -3 },
	{ "3-(2+1-2*5/8)+(4-9)",      "321+258/*--49-+" , -3.75 },
	{ "3-(2+(1-2)*5/8)+(4-9)",    "3212-58/*+-49-+", -3.375 },
	


};
uint8 test_num = ARRAY_COUNT(gain_expect);


int test_expression_calculator(void)
{
    uint8 data = 0;
	double value = 0;

	for (size_t i=0; i < test_num;i++)
	{
		String infix_expression = gain_expect[i].gain_expression;
		char suffix_expression[255];

		value = calculate(infix_expression, suffix_expression);
		
		printf("后缀表达式为：%s\n %s = %f\n\n", suffix_expression, infix_expression, value);

		assert(gain_expect[i].expect_expression, suffix_expression);
	}
    return 0;
}




