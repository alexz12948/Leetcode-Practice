Title: C++ || Easy to Understand with In-Depth Explanation || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

We want to see if the characters of s all exist inside of t in order. If all characters are there, then s must be a subsequence of t

# Approach

The way that I did this is created an iterator that was looking at the first index of s (`s_idx`). Then as I iterated through t, if `t[i] == s[s_idx]`, then I increamented the s_idx by 1. 

The reason why I can do this is because essentially all of the characters that don't fall into the condition can be deleted in the final product. Remember, we just want to see if all of the characters of s exist in t IN ORDER.

At the end of the iteration, if s_idx is equal to the size of s, then we know that all of the characters of s exist in t in order, which is what we are looking for

# Complexity

**Time Complexity:** $$O(n)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int n = t.size();
        int s_idx = 0;
        for (int i = 0; i < n; i++)
            if (t[i] == s[s_idx])
                s_idx++;

        return s_idx == s.size();
    }
};
```