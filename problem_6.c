/* The sum of the squares of the first ten natural numbers is,
 * 1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 * (1 + 2 + ... + 10)2 = 552 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural
 * numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 */

#include <stdio.h>
#include <math.h>

int main()
{
    int squared_sum = 0;
    int sum_squared = 0;
    for (int i=1; i<=100; i++)
    {
        squared_sum += pow(i, 2);
        sum_squared += i;
    }
    int diff = pow(sum_squared, 2) - squared_sum;
    printf("%i\n", diff);
    return 0;
}
