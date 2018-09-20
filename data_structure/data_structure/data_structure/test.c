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

    stack.init(10);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);

    for (int i = 0;i<10;i++)
    {
        stack.pop(&data);
        printf("%d ", data);
    }
    printf("%d\n");
    stack.push(8);
    for (int i = 0; i < 10; i++)
    {
        stack.pop(&data);
        printf("%d ", data);
    }
    return 0;
}




