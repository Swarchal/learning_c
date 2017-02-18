/* projectuler problem 3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>

int main()
{
    long n = 600851475143;
    long factor = 2;

    while (n > factor)
    {   
       //printf("%li\t%li\n", n, factor);
       if (n % factor == 0)
       {
            n /= factor;
            factor = 2;
       }
       else
       {
            factor ++;
       }
    }
    printf("%li\n", factor);
    return 0;
}

