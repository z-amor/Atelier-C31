#include <stdio.h>

/** ligne 1:   #
*   ligne 2:  ##
*   ligne 3: ###
*   ligne 4:####
*/

void print_triangle(int size)
{
    int row,col;

    if (size <= 0)
    {
        putchar('\n');
        return;
    }

    row = 1;
    while (row <= size)
    {
        col = 0;
        while (col < (size - row))
        {
            putchar(' ');
            col++;
        }
        col = 0;
        while (col < row)
        {
            putchar('#');
            col++;
        }
        putchar('\n');
        row++;
    }
}

int main(void)
{
    print_triangle(4);
    print_triangle(10);
    return (0);
}