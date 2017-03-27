
/* project euler # 14

 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)

 * Using the rule above and starting with 13, we generate the following sequence:
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting
 * numbers finish at 1.

 * Which starting number, under one million, produces the longest chain?

 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */


#include <stdio.h>

// given a starting number n, this function will return the
// number of elements in the collatz sequence before reaching 1
int len_collatz(long n)
{
    int len = 1;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        } else // is odd
        {
            n = 3*n + 1;
        }
        len++;
    }
    return len;
}


int main()
{
    static const int limit = 1000000;
    int current_max = 0;
    int max_starting;
    int len;
    for (int i=3; i<limit; i+=2)
    {
        len = len_collatz((long) i);
        if (len > current_max)
        {
            current_max = len;
            max_starting = i;
        }
    }
    printf("%i\n", max_starting);
    return 0;
}