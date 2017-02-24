/* project euler problem 5
 *
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the
 * numbers from 1 to 20?
 */

#include <stdio.h>

int main()
{
    int n = 1;
    int total = 0;
    while (total < 20)
    {
        for (int i=1; i<=20; i++)
        {
            if (n % i == 0)
            {
                total++;
            }
            else
            {
                total=0;
                n++;
                break;
            }
        }
    }
    printf("%i\n", n);
    return 0;
}
