C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Loop through all the strings and perform the operations that they described:

1. If it is a number, then use that as the value
2. if it isn't a number, then use the length of the string as the value

# Approach

First, I wrote an isNumber function since that doesn't really exist in C++. Then if the string is a number, then I take the max between the current max value and the string converted to a number. Otherwise, I take the max between the current max value and the length of that string.

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        const int n = strs.size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (isNumber(strs[i]))
                ans = max(ans, stoi(strs[i]));
            else
                ans = max(ans, (int)strs[i].size());
        }

        return ans;
    }
private:
    bool isNumber(string s) {
        for (int i = 0; i < s.size(); i++)
            if (!isdigit(s[i]))
                return false;
        return true;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**