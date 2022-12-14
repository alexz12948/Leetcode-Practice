C++ || Easy to Understand with In-Depth Explanation and Examples || O(N*M)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

We know that there is only 1 unique way to get to the upper row and left column. Then, we also know that there is only 2 unique ways to get to the index `(1,1)` (0 indexed): either from the top row or the first column. Notice that the answer is the sum of the unique ways to get to `(1,0)` and `(0,1)`. Therefore, we need to create a `m x n` grid and compute `dp[i][j] = dp[i - 1][j] + dp[i][j - 1]`. 

# Approach

Initialize an `m x n` grid to have all ones and run from `1` to `m - 1` and `1` to `n - 1` and compute `dp[i][j]` described in the [intuition](#intuition)

# Complexity

**Time Complexity:** $$O(N*M)$$
**Space Complexity:** $$O(N*M)$$

# Code

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 1));

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m - 1][n - 1];
    }
};
```

# O(N) Space Complexity

I felt that the most effective solution was best explained in [this post](https://leetcode.com/problems/unique-paths/solutions/22954/c-dp/?orderBy=most_votes) so feel free to check it out if you are interested!

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**