/* project euler # 21
 *
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 * which divide evenly into n).
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and
 * each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55
 * and 110; therefore d(220) = 284. The proper divisors of 284 are
 * 1, 2, 4, 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000
 */

#include <stdio.h>
#include <math.h>

// sum of proper divisors
int d(int n)
{
    int total = 0;
    for (int i=1; i<n; i++)
    {
        if (n % i == 0)
        {
            total += i;
        }
    }
    return total;
}


int main()
{
    int total = 0;

    for (int i=1; i<10000; i++)
    {
        int sum_div = d(i);

        if (d(sum_div) == i && sum_div != i)
        {
            total += i;
        }
    }
    printf("%i\n", total);
    return 0;
}
