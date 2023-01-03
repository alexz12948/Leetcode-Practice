C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Check if all the characters of `s` occur in `t`, in order

## Code

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

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

To check if `s` is a subsequence of `t`, we want to see if all of the characters within `s` occur inside of `t` in order. This is because if we strip away all of the extra characters in `t`, we should be left with `s`

## Approach 

The way that I did this is created an iterator that was looking at the first index of s (`s_idx`). Then as I iterated through t, if `t[i] == s[s_idx]`, then I increamented the s_idx by 1. 

The reason why I can do this is because essentially all of the characters that don't fall into the condition can be deleted in the final product. Remember, we just want to see if all of the characters of s exist in t IN ORDER.

At the end of the iteration, if s_idx is equal to the size of s, then we know that all of the characters of s exist in t in order, which is what we are looking for

## Example

Lets use the first example, where `s = "abc"` and `t = "ahbgdc"`

| i | s_idx | t char | s char | Result     |
|---|-------|--------|--------|------------|
| 0 | 0     | a      | a      | Increament |
| 1 | 1     | h      | b      | Nothing    |
| 2 | 1     | b      | b      | Increament |
| 3 | 2     | g      | c      | Nothing    |
| 4 | 2     | d      | c      | Nothing    |
| 5 | 2     | c      | c      | Increament |

At the end, `s_idx = s.size() = 3` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**