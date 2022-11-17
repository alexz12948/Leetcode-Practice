/*
Explanation of Solution
-----------------------

The basic idea is to use precomputed information to help later on, which is
why we utilize another auxilliary rectangle (sorta like dp)

The basic idea is that we want to calculate the biggest square that we can
from a cell, which would be the bottom right corner in our case. Then, for
a particular cell, we can calculate the biggest square for a square with the
bottom right corner in cell (i,j) by doing:
min(a[i - 1][j], a[i][j - 1], a[i - 1][j - 1])
assuming that the corner is a one itself

This allows you to know for sure that you can make a square from your particular point
which can be shown with a drawing

Note about auxiliarry data structure - this array is 1-indexed as well as
for all values where the row or column is one the max square size is 0 since
it is outside of the normal matrix location

Complexity
----------
Time: O(nm)
Space: O(nm) 
*/

const int sideMax = 301;
// Note that 
int maxSquareSize[sideMax][sideMax];

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    const int n = matrix.size(), m = matrix[0].size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
      maxSquareSize[i][0] = 0; 
      for (int j = 0; j < m; j++) {
        maxSquareSize[0][j] = 0;
        maxSquareSize[i + 1][j + 1] = matrix[i][j] == '1'
          ? 1 + min({maxSquareSize[i][j], 
                     maxSquareSize[i + 1][j], 
                     maxSquareSize[i][j + 1]})
          : 0;
        ans = max(ans, maxSquareSize[i + 1][j + 1]);
      }
    }

    return ans * ans;
  }
};