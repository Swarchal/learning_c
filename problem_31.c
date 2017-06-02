#include <stdio.h>

int main()
{
    const int target = 200;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};

    // initialise array to all zeros, first value as 1
    int n[target];
    for (int i = 0; i <= target; i++) n[i] = 0;
    n[0] = 1;

    for (int i = 0; i <= 8; i++) {
        for (int j = coins[i]; j <= target; j++) {
            n[j] += n[j - coins[i]];
        }
    }

    printf("%i\n", n[target]);
    return 0;
}
