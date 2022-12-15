C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Use sliding window, keep track of the character that occurs most in the window, and continuously shrink the window when there are more than k elements that have to be replaced in the window.

# Approach

We need to initialize a bunch of variables:

* `ans = k` since we know that the answer is at least equal to k because we can replace `k` characters
* `left = 0` since that is the start of the window
* `maxCharCount = 0` which is the character that occurs most in the window's frequency
* `curr_len` which is the current length of the window
* `unordered_map<char,int> freq` to keep track of the frequency

Then we iterate through the string and increase the frequency of the right pointer and update the maxCharCount. If `curr_len - maxCharCount > k` (which means that the window has more characters that it can replace), we need to shrink the window by reducing the frequency of the left endpoint and moving the left endpoint in to make the array valid again (since it can be no more than 1 character off). We then update the answer and continue

# Example

Let `s = "AABABBA"` and `k = 1` and we are at the point where the left is at index `0` and the right pointer is at index `3`.

The frequency is: `{'A': 2, 'B': 1}`

|**Character**|A|A|B|A|B|B|A|
|---|---|---|---|---|---|---|---|
|**Index**|0|1|2|3|4|5|6|
|**Pointers**|left| | |right| | | |

We update the frequency so that `'A': 3` and keep that as the `maxCharCount`. Then we know that `curr_len = 4` and `curr_len - maxCharCount = 1` so we know that this window is valid so we update answer to be 4 (which is essentially like replacing `'B'` with `'A'`)

In the next iteration, it looks like this:

|**Character**|A|A|B|A|B|B|A|
|---|---|---|---|---|---|---|---|
|**Index**|0|1|2|3|4|5|6|
|**Pointers**|left| | | |right| | |

We update the frequency so that `'B': 2` and still keep `'A': 3` as the `maxCharCount`. Then we know that `curr_len = 5` and `curr_len - maxCharCount = 2`, so we know that the window is no longer valid since essentially we would have to replace both `'B'`'s that exist in the window. We then shrink the window and update the answer

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

# Code

```c++
class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.size();

        int ans = k, left = 0, maxCharCount = 0, curr_len;
        unordered_map<char,int> freq;
        for (int right = 0, right < n; right++) {
            freq[s[right]]++;
            maxCharCount = max(maxCharCount, freq[s[right]]);

            curr_len = right - left + 1;
            if (curr_len - maxCharCount > k) {
                freq[s[left]]--;
                left++;
                curr_len--;
            }

            ans = max(ans, curr_len);
        }

        return ans;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**