#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * p1 = (int *) malloc(16);
    int * p2 = (int *) malloc(0);
    printf("p1 is %p, p2 is %p\n", p1, p2);
    free(p1);
    free(p2);
}