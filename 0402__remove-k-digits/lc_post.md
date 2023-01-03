C++ || O(N) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Use string as a monotonically increasing stack of digits until `k` digits are removed, then add the remaining digits

## Code

```c++
class Solution {
public:
    string removeKdigits(string num, int k) {
        const int n = num.size();
        string ans;

        for (char c : num) {
            while (!ans.empty() && ans.back() > c && k > 0) {
                ans.pop_back();
                k--;
            }

            if (!ans.empty() || c != '0')
                ans.push_back(c);
        }

        while (k > 0 && !ans.empty()) {
            k--;
            ans.pop_back();
        }

        return ans == "" ? "0" : ans;
    }
};
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

The basic idea is that you want to use a stack that holds values in increasing values otherwise known as a increasing monotonic stack

## Approach 

Opposed to using a traditional stack, I am going to use a string since it has all the operations that I would need from a stack but it would just allow me to not have to move all the elements off of a stack and put them into a string at the end (might as well use what I have from the beginning!)

First, we iterate through all of the characters and if the queue is not empty OR the character is not a '0', then we push it onto the stack. The reason for this logic is to prevent adding leading zeros to the solution.

As we iterate, we need to maintain a increasing monotonic stack. In order to do that, we need to check if the top of the stack's value is greater than the current character that we are looking at. If so, then we pop the value off of the top and count that digit as removed (`k--`). We just need to ensure that we still have characters to pop off, which comes from the check `k > 0` in the while loop condition.

The second while loop outside of the normal iteration is for a case where there is a substring that is increasing and we can still pop values off. What happens is that while there are still values to pop off the stack and we can still remove characters from the string, we pop the back values off since they must have been increasing.

At the end, if the answer string is empty, then we just return 0 since we can remove all the characters. Otherwise, we just return the answer string

## Example

Lets use the first example, where `num = "1432219"` and `k = 3`

* c = '1'
ans = `""`
k = 3

There is nothing in the string yet, so just add to the answer

* c = '4'
ans = `"1"`
k = 3

`ans.back() > c` $$\rightarrow$$ `1 > 4` is `false`, so we just add the character onto the answer

* c = '3'
ans = `"14"`
k = 3

`ans.back() > c` $$\rightarrow$$ `4 > 3` is `true`, so we pop the back value off and subtract `k` by 1

ans = `"1"`
k = 2

`ans.back() > c` $$\rightarrow$$ `1 > 3` is `false`, so we just add the character onto the answer

* c = '2'
ans = `"13"`
k = 2

`ans.back() > c` $$\rightarrow$$ `3 > 2` is `true`, so we pop the back value off and subtract `k` by 1

ans = `"1"`
k = 1

`ans.back() > c` $$\rightarrow$$ `1 > 2` is `false`, so we just add the character onto the answer

* c = '2'
ans = `"12"`
k = 1

`ans.back() > c` $$\rightarrow$$ `2 > 2` is `false`, so we just add the character onto the answer

* c = '1'
ans = `"122"`
k = 1

`ans.back() > c` $$\rightarrow$$ `2 > 1` is `true`, so we pop the back value off and subtract `k` by 1

ans = `"12"`
k = 0

`k` is now 0, so we just add the other values onto the string as long as they aren't `0`s. The final characters are `1` and `9`, so the final string becomes `"1219"` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**