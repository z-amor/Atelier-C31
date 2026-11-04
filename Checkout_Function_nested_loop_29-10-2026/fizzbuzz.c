#include <stdio.h>



int main(void)
{
    int i = 15;

    if (i % 3 == 0 && i % 5 == 0)
        printf("FizzBuzz\n");
    else if (i % 3 == 0)
        printf("FIZZ\n");
    else if (i % 5 == 0)
        printf("BUZZ\n");
    else 
        printf("%d\n", i);

    return (0);
}