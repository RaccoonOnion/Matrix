#include <stdio.h>
#include <stdlib.h>

int main()
{
    float * p1 = (float *) malloc(16);
    int * p2 = (int *) malloc(0);
    printf("p1 is %p, p2 is %p\n", p1, p2);
    p1[0] = 2.0f;
    printf("value is %f", p1[0]);
    free(p1);
    free(p2);
}