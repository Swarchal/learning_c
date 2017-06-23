// project euler #34
#include <stdio.h>

int factorial(int n) {
    int ans = 1;
    for (int i=1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}


int main() {
    const int LIMIT = 1000000; // ????
    int total = 0;

    for (int i = 10; i <= LIMIT; i++) {
        int tmp_total = 0;
        // make a copy to modify, so we keep original to compare at the end
        int i_copy = i;

        // iterate through digits of i
        while (i_copy > 0) {
            int digit = i_copy % 10;
            tmp_total += factorial(digit);
            i_copy /= 10;
        }

        if (tmp_total == i) {
            total += i;
        }
    }
    printf("%i\n", total);
    return 0;
}
