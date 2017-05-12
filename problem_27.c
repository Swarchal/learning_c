// project euler # 27
// brute force solution

#include <stdio.h>
#include <math.h>

// 1 if n is prime, 0 if n is not prime
int is_prime(int n)
{
    if (n < 2 || n % 2 == 0)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    for (int i=3; i<(n/2+1); i+=2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}


// number of consecutive primes given coeffiecients a and b
// for incremental n, starting with n=0
// n^2 + a*n + b
int n_consecutive_primes(int a, int b)
{
    int n = 0;
    int still_prime = 1;

    while (still_prime == 1)
    {
        int num = (int) (pow(n, 2) + a*n + b);
        still_prime = is_prime(num);
        n++;
    }
    return n-1;
}


int main()
{
    int current_max = 0;
    int n_primes, coef_product;

    for (int a=-999; a<=999; a++)
    {
        for (int b=-1000; b<=1000; b++)
        {
            n_primes = n_consecutive_primes(a, b);
            if (n_primes > current_max)
            {
                current_max = n_primes;
                coef_product = a * b;
            }
        }
    }
    printf("%i\n", coef_product);
    return 0;
}
