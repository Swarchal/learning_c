#include <stdio.h>

int main()
{
    int target = 200;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int n[target];

    // initialise array to all zeros, first value as 1
    for (int i = 0; i <= target; i++) n[i] = 0;
    n[0] = 1;

    for (int j = 0; j <= 8; j++)
    {
        for (int k = coins[j]; k <= target; k++)
        {
            n[k] += n[k - coins[j]];
        }
    }

    printf("%i\n", n[target]);
    return 0;
}
