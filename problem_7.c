/* project euler problem 7
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
 * we can see that the 6th prime is 13.
 * What is the 10,001st prime number?
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define limit 1000000

// return pointer to an array of sieved prime numbers
char* create_sieve(void)
{
    // create pointer to heap in memory of size type * n
    char *A = malloc(sizeof(short) * limit);
    // set all values in array to 1
    for (int i=0; i<=limit; i++)
    {
        A[i] = 1;
    }

    // sieve of Eratosthenes to find primes up to limit
    // iterate through array of integers (initially all 1)
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

    int prime_count = 0;
    int current_prime;

    // iterate through sieve, count number of primes (1's)
    // return the index of the 10,001st prime
    for (int k=2; k<=limit; k++)
    {
        if (A[k] == 1) // then it's prime
        {
            prime_count ++;
            current_prime = k;

            if (prime_count == 10001)
            {
                printf("%i\n", current_prime);
                return 0;;
            }

        }
    }
}
