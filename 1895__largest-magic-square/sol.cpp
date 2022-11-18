/*
Explanation of Solution
-----------------------

I did look at the solution, however I did think of the correct answer! I just
thought it was wrong lmao

The basic idea is holding 4 different prefix sums for the rows, cols, and 2
diagonals. After computing the prefix sums, then loop through all of the
top left corners of a possible square and then try all possible squares going
from largest to smallest with the smallest value ans + 1. 
When you have a square size k, then check to see if the rows, cols and diagonals
all add up to a particular sum. If that is true, then you found a better solution
so you update ans

Complexity
----------
Time: O(nm * min(n,m)^2)
Space: O(nm) 
*/
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        const int m = size(grid), n = size(grid[0]);
        int ans = 0;

        vector<vector<int>> rows(m + 2, vector<int>(n + 2)), 
                            cols(rows), 
                            d1(rows), 
                            d2(rows);

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                rows[i][j] += grid[i - 1][j - 1] + rows[i][j - 1];
                cols[i][j] += grid[i - 1][j - 1] + cols[i - 1][j];
                d1[i][j] += grid[i - 1][j - 1] + d1[i - 1][j - 1];
                d2[i][j] += grid[i - 1][j - 1] + d2[i - 1][j + 1];
            }

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                for (int k = min(m - i, n - j); k > ans; k--) {
                    int sum = d1[i + k][j + k] - d1[i - 1][j - 1];
                    bool valid = sum == (d2[i + k][j] - d2[i - 1][j + k + 1]);
                    for (int l = 0; l <= k && valid; l++) {
                        valid &= sum == rows[i + l][j + k] - rows[i + l][j - 1];
                        valid &= sum == cols[i + k][j + l] - cols[i - 1][j + l];
                    }

                    ans = valid ? k : ans;
                }
    
        return ans + 1;
    }
};
