/* project euler # 15
 * 
 * Starting in the top left corner of a 2×2 grid, and only being able to move to
 * the right and down, there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 */

#include <stdio.h>
#include <math.h>

int main()
{
    const int n=20;
    
    // create 21 by 21 array
    long arr[n+1][n+1];

    // pad top row and first column with all 1's  
    for (int i=1; i < (n+1); i++)
    {
        arr[0][i] = 1;
        arr[i][0] = 1;
    }

    // loop through rows and col, number of combinations to
    // get to index is (index above) + (index left)
    for (int row=1; row < (n+1); row++)
    {
        for (int col=1; col < (n+1); col++)
        {
            arr[row][col] = arr[row-1][col] + arr[row][col-1];
        }
    }

    // print bottom right index    
    printf("%li\n", arr[n][n]);
    return 0;
}