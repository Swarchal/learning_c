/* project euler : problem 9
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for
 * which,
 * a2 + b2 = c2
 *
 * For example, 32 + 42 = 9 + 16 = 25 = 52.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <stdio.h>
#include <math.h>

// brute force it
int main()
{
    int a, b, c, product;
    int perim = 1000;

    // only test sides that will have a perimeter of 1000 (or close enough)
    for (a = 3; a < perim / 3; a++)
    {
        for (b = a+1; b < (perim - a) / 2; b++)
        {
            c = perim - a - b;

            // if pythagorean triplet, print product of 3 sides
            if (pow(c, 2) == pow(a, 2) + pow(b, 2))
            {
                product = a * b * c;
                printf("%i\n", product);
                return 0;
            }
        }
    }
}
