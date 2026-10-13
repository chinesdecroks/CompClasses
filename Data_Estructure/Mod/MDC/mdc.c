#include <stdio.h>
#include "mdc.h"

int max_div_com(int a, int b)
{
    int m, mdc;
    if (a <= b)
        m = a;
    else 
        m = b;

    for (int i = 1; i <= m; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            mdc = i;            
        }
    }

    return mdc;
}