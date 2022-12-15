C++ || Easy to Understand with In-Depth Explanation and Examples || O(NM)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Use bottom up DP and keep track of the longest common subsequence for a particular index i and j of the strings. 

# Approach

Initialize a matrix to be n + 1 rows and m + 1 columns since we want the outer border to be initialized to 0 (since there is no LCS with one of the strings being empty)

Then we know that $$LCS(i,j)$$ has two cases

1. $$text1[i] == text2[j]$$
2. The characters at $$i$$ and $$j$$ are not equal

Therefore, in code:

1. If `text1[i] == text2[j]`:
`dp[i][j] = dp[i - 1][j - 1] + 1` since we want to find the LCS of the character before in each string
2. If `text1[i] != text2[j]`:
`dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])` since we want to find the longest subsequence and we want to delete this character since it doesn't help us. We take the max between the character before in `text1` and the character before in `text2`

# Example

Lets say `text1 = "vwxyz"` and `text2 = "vxz"` where we can see that the answer is `2`. Try to follow the grid below and make sure you understand

| | |v|w|x|y|z|
|---|---|---|---|---|---|---|
| |**0**|0|0|0|0|0|
|v|0|**1**|**1**|1|1|1|
|x|0|1|1|**2**|**2**|2|
|z|0|1|1|2|2|**3**|

# Complexity

**Time Complexity:** $$O(nm)$$
**Space Complexity:** $$O(nm)$$

# Code

```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int n = text1.size(), m = text2.size();
        vector<vector<short>> matrix (n + 1, vector<short> (m + 1, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                matrix[i + 1][j + 1] = text1[i] == text2[j] 
                    ? matrix[i][j] + 1 
                    : max(matrix[i + 1][j], matrix[i][j + 1]);

        return matrix[n][m];
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**