#include<stdio.h>

int a = 1;
#define A   a

int main()
{
    printf("a = %d!",a);

    a = 2;
    printf("A = %d, a = %d!",A,a);

    return 0;
}