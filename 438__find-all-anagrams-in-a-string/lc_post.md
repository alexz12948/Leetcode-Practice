C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Keep track of the frequency of `s` and `p`, iterate over `s` to see if the subarray of length m (`p.size()`) is an anagram of p

# Approach

If the length of `p` is greater than the length of `s`, then no anagrams are possible, so we return an empty vector

We use similar to a sliding window technique where we create a window of length `m` (`p.size()`) and keep track of the frequency of s in a subarray of length `m` and ending at `i` as we iterate. If the frequency of the characters in `s` is equal to the frequency of all the characters in `p`, then we know that there is an anagram so we push back the first index of the anagram to the answer vector.

# Example 

Lets say `s = "cbaebabacd"` and `p = "abc"`

We know that `p_freq = {'a': 1, 'b': 2, 'c': 3}` from the first loop

Then we iterate over the characters in s and keep track of the frequency. If `i >= m` indicates that the subarray is of proper size now. If it is, we want to remove the character that is outside of the subarray and if its frequency reaches 0, then we want to remove it from the array entirely (since otherwise it won't do a proper comparison of the s frequency and p frequency)

A good point to show this is when `i = 3`. When this occurs `i >= m` since `m = 3`, so we want to remove `s[i - m] = s[3 - 3] = s[0] = 'c'` from the subarray since we only want to look at the subarray from 1 to 3 (3 indices).

If the frequency of s equals the frequency of p, then we push back the start of the anagram to the answer.

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

# Code

```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n = s.size(), m = p.size();
        if (m > n)
            return {};

        unordered_map<char,int> p_freq, s_freq;
        vector<int> ans;
        for (int i = 0; i < m; i++)
            p_freq[p[i]]++;

        for (int i = 0; i < n; i++) {
            s_freq[s[i]]++;
            if (i >= m)
                if (--s_freq[s[i - m]] == 0)
                    s_freq.erase(s[i - m]);

            if (s_freq == p_freq)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**