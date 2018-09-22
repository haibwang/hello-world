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




int main(void)
{
    uint8 data = 0;
    String infix_expression="9+(3-1)*3+10/2";
    char suffix_expression[255];

    calculate(infix_expression, suffix_expression);

    printf("%s", suffix_expression);
    return 0;
}




