/* project euler problem 10
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define limit 2000000

// return pointer to an array of sieved prime numbers
char* create_sieve(void)
{
    // create pointer to heap in memory of size n * type
    char *A = malloc(limit * sizeof(short));

    // set all values in array to 1
    for (int i=0; i<=limit; i++)
    {
        A[i] = 1;
    }

    // sieve of Eratosthenes to find primes up to limit
    for (int i=2; i<=floor(sqrt(limit)); i++)
    {
        if (A[i] == 1)
        {   // set all multiples of primes to 0
            for (int j=i*i; j<=limit; j+=i)
            {
                A[j] = 0;
            }
        }
    }
    return A;
}


int main()
{
    const char *A = create_sieve();
    long prime_total = 0;

    // iterate through sieve, count number of primes (1's)
    for (int k=2; k<limit; k++)
    {
        if (A[k] == 1) // then it's prime
        {
            prime_total += k;
        }
    }

    printf("%li\n", prime_total);
    return 0;
}
