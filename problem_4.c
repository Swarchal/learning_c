/* A palindromic number reads the same both ways.
 * The largest palindrome made from the product
 * of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers
 */

#include <stdio.h>

// reverse an integer by modulo and integer division
int reverse(int n)
{
    int reversed = 0;
    while (n != 0)
    {
        reversed = reversed * 10;
        reversed = reversed + n % 10;
        n /= 10; // int division, so removes final digit 
    }
    return reversed;
}


int main()
{
    long max_palindrome = 0;
    for (int i=999; i>=100; i--)
    {
        for (int j=999; j>=100; j--)
        {
            int value = i * j;
            if (value == reverse(value))
            {
                if (value > max_palindrome)
                {
                    max_palindrome = value;
                }
            }
        }
    }
    printf("%li\n", max_palindrome);
    return 0;
}
