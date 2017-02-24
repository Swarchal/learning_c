/* A palindromic number reads the same both ways.
 * The largest palindrome made from the product
 * of two 2-digit numbers is 9009 = 91 × 99.
 * 
 * Find the largest palindrome made from the product of two 3-digit numbers
 *
 * can actually just do this in your head:
 *     largest palindrome number than 998001 (999*999) is 997799
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
    int upper_limit = 999 * 999;
    int lower_limit = 100*100;

    for (int i = upper_limit; i >= lower_limit; i--)
    {
        if (i == reverse(i))
        {
            printf("%i\n", i);
            break;
        }
    }
    return 0;
}
