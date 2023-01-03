C++ || Easy to Understand with In-Depth Explanation and Examples || O(N^2)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Use dynamic programming to keep track of all of the possible falling paths. In the last row, it should have the minimum sum of the path that it would take to get to a particular `(n - 1,j)`. 

In other words, we want to find the minimum sum that it would take to get to a particular index `(i,j)`. So, we need to find the minimum of all of the paths that you could take to get to one of the elements above you. This is why dynamic programming is perfect for this question. Here is the mathematical equation:

$$dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j]$$ where we ensure that $$j \in [1,n-1]$$ to ensure that it stays in bounds

# Approach

Create an `n x n` matrix to store the minimum sum that it takes to get to a particular index `(i,j)`.

First, we assign the first row of the matrix to be the first row of dp since the minimum sum to get to the first row is the element that you are on

Then, we loop through all the elements from from 1 to n - 1 and use the equation above to find the minimum path that it would take to a particular location. Note that the function `getMinOfAbove` strictly finds the minimum path of the indices above it and ensure that we stay in bounds.

At the end, we just return the minimum element from the last row of the dp matrix since we are looking for the minimum sum path to go from the top of the array to the bottom

# Complexity

**Time Complexity:** $$O(n^2)$$
**Space Complexity:** $$O(n^2)$$

# Code

```c++
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];

        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = matrix[i][j] + getMinOfAbove(dp, i, j);

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
private:
    int getMinOfAbove(vector<vector<int>>& m, int row, int col) {
        if (col == 0)
            return min(m[row - 1][col], m[row - 1][col + 1]);
        else if (col == m.size() - 1)
            return min(m[row - 1][col], m[row - 1][col - 1]);

        return min({m[row - 1][col - 1], m[row - 1][col], m[row - 1][col + 1]});
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**