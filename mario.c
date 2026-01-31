#include <cs50.h>
#include <stdio.h>

void print_spaces(int spaces);
void print_row(int bricks);

int main(void)
{
    // prompt user for input
    int height;

    do
    {
        height = get_int("Heigh: ");
    }
    while (height < 1);
    int spaces = height;
    for (int i = 0; i < height; i++)
    {
        print_spaces(spaces);
        print_row(i + 1);
        spaces--;
    }
}

void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
void print_spaces(int spaces)
{
    for (int i = spaces - 1; i > 0; i--)
    {
        printf(" ");
    }
}
