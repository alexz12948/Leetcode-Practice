/*
Explanation of Solution
-----------------------

You only need to use one for loop since the row iteration is
the same and the column are inverses. Therefore, all you need is

mat[i][i] + mat[n - i - 1] to get the sum of the elements you care
about in the row. Also, if the side length is odd, then you need to
subtract off the middle value since it would've been counted twice

Complexity
----------
Time: O(n)
Space: O(1) 
*/
class Solution {
public:
  int diagonalSum(vector<vector<int>>& mat) {
    const int n = mat.size();

    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += mat[i][i] + mat[i][n - i - 1];

    return n % 2 == 0 ? ans : ans - mat[n / 2][n / 2];
  }
};