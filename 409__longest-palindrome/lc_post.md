Title: C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Get the frequency of every character and determine the number of pairs of characters that can be used to create a palandromic string plus 1 if there is an odd frequency (to account for strings that are of odd length)

For example, if `s = "abccccdd`, we know that all of the `c` and `d` can be used since we can just put them at opposite ends of the string. Also notice that the frequency of `a` and `b` are odd (both have 1), therefore they could go in the middle. An example solution could be `"ccdadcc"`

# Approach

First, we just get the frequencies of all the characters. Then we initialize the answer to be 0 and a boolean to determine whether or not there is an odd frequency.

Then we add on the amount of characters of that frequency rounded down to the nearest multiple of 2. The mathematical equation is $$\lfloor{\frac{n}{2}} \rfloor * 2$$. For example, if a character has a frequency of 5, then we are saying 4 of those characters could be used for the palindromic string.

Also, we are checking if any of the frequencies are odd. If so, then we need to add one onto the answer at the end.

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
class Solution {
public:
    int longestPalindrome(string s) {
        const int n = s.size();
        unordered_map<char,int> freq;

        for (int i = 0; i < n; i++)
            freq[s[i]]++;

        int ans = 0;
        bool hasOdd = false;
        for (pair<char,int> f : freq) {
            ans += (f.second / 2) * 2;
            hasOdd |= f.second % 2 == 1;
        }

        return hasOdd ? ans + 1 : ans;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**