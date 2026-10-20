#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordena.h"

int main(void)
{

    /*Quick Sort
    int t = 6;
    int v[] = {34, 7, 23, 32, 5, 62};
    show(v, t);
    quickSort(v, 0, t-1);
    show(v, t);
    */


    int *v = (int *)malloc(10*sizeof(int));
    v = randVector(10, 100);

    show(v, 10);

    mergeSort(v, 0, 9);

    show(v, 10);

}