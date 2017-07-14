/* rosalind: aspc
 *
 * Given positive integers n and m
 * Return the sum of combinations C(n, k) for all k satifying m <= k <= n
 * mod 1,000,000
 */


#include <stdio.h>


long factorial(int n)
{
    long ans = 1;
    for (int i = n; i > 0; i--)
    {
        ans *= i;
    }
    return ans;
}


long n_comb(long n, long r)
{
    return factorial(n) / factorial(r) / factorial(n - r);
}


int main()
{
    const int n = 6;
    const int k = 3;

    long answer = 0;

    for (int i = k; i <= n; i++)
    {
        answer += n_comb(n, i) % 1000000;
    }

    printf("%li\n", answer);
    return 0;
}
