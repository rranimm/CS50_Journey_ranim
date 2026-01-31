#include <cs50.h>
#include <stdio.h>

int first_two_digits(long number);

int main(void)
{
    long number = get_long("Number: ");
    int sum_1 = 0; // for digits that won't get multiplied
    int sum_2 = 0; // for digits that'll multiply by 2
    int counter = 0;
    long original_number = number;

    while (number > 0)
    {
        int digit = number % 10;

        if (counter % 2 == 0)
        {
            sum_1 += digit;
        }
        else
        {
            int multiplied = digit * 2;
            sum_2 += (multiplied / 10) + (multiplied % 10);
        }
        number = number / 10;
        counter++;
    }
    int total = sum_1 + sum_2;

    if (total % 10 == 0)
    {
        int first_two = first_two_digits(original_number);
        int first_digit = first_two / 10;

        // AMEX: 15 digits, starts with 34 or 37
        if (counter == 15 && (first_two == 34 || first_two == 37))
        {
            printf("AMEX\n");
        }
        // MASTERCARD: 16 digits, starts with 51-55
        else if (counter == 16 && (first_two >= 51 && first_two <= 55))
        {
            printf("MASTERCARD\n");
        }
        // VISA: 13 or 16 digits, starts with 4
        else if ((counter == 13 || counter == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
int first_two_digits(long number)
{
    while (number >= 100)
    {
        number /= 10;
    }
    return number;
}
