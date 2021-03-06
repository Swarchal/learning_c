/* project euler problem 2
 *
 * Each new term in the Fibonacci sequence is generated by adding the previous
 * two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms.
 */

#include <stdio.h>

int main()
{
    long first = 0;
    long second = 1;
    long next;
    long sum_even = 0;

    while (first <= 4000000)
    {
        if (first % 2 == 0)
        {
            sum_even += first;
        }

        next = first + second;
        first = second;
        second = next;
    }
    printf("%li\n", sum_even);
    return 0;
}
