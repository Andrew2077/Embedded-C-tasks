#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




int x;
int y;

int z; 

int add(int x)
{
    x = x + 1;
    return x;
}

int main(void)
{
    x = 5;
    x = add(x);
    printf("%d", x);
    return 0;
}

