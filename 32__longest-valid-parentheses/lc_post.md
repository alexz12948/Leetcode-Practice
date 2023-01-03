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

All we want to do is scan the string from start to finish and use a stack to figure out if the index we are still looking at is a valid parenthesis

In other words, we want to push the indices of the opening brackets and if you encounter a closing bracket, then we calculate how long was this valid parenthesis (assuming that the stack is not empty) and update the ans if it is longer than the current best

## Code

```c++
#define OPEN_BRACKET '('

class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        int ans = 0;
        stack<int> brackets;
        brackets.push(-1);
        for (int i = 0; i < n; i++) {
            if (s[i] == OPEN_BRACKET)
                brackets.push(i);
            else {
                brackets.pop();
                if (brackets.empty())
                    brackets.push(i);
                else
                    ans = max(ans, i - brackets.top());
            }
        }

        return ans;
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

This is a modified version of the valid parenthesis problem

We initially push `-1` onto the stack because it is to indicate the last location of a valid parenthesis. At first, the last valid parenthesis finished at index `-1`. Then, every time we encounter an opening bracket, we want to push that onto the stack too. 

If it isn't an opening bracket (aka closing bracket), we want to pop off the stack. If the stack is not empty, that means we have encountered a valid parenthesis and the stack's current top is the position before the start of the valid string. Therefore, taking the difference between the current index and the stack's top will yield the length of the valid string and we update the answer if it is longer than the current best.

If the stack is empty, that means that we have no idea where the next valid parenthesis set is (since we always compare it to the stack's top element). Therefore, we just push the current index onto the stack to indicate the location of the last valid parenthesis.

## Approach 

We initialize push `-1` onto a stack and we iterate through all the characters in `s`. If the current character is a open bracket, push the index onto the stack. Otherwise, we pop off of the top. If the stack then becomes empty, we push the current index onto the stack. Otherwise, we update the answer to be the difference between the current index and the current stack top's value

## Example

Lets use the second example, where `s = ")()())"`

First, we push `-1` onto the stack since that the last valid location so far

* i = 0
Stack = [-1] <-- TOP
Ans = 0

`s[0] = ')'`, so we pop off of the stack. Since it is empty now, we push `i = 0` onto the stack

* i = 1
Stack = [0] <-- TOP
Ans = 0

`s[1] = '('`, so we push `i = 1` onto the stack

* i = 2
Stack = [0,1] <-- TOP
Ans = 0

`s[2] = ')'`, so we pop off of the stack (`1`). Then, we update ans to be the max between itself and `i - stack.top() = 2 - 0 = 2`

* i = 3
Stack = [0] <-- TOP
Ans = 2

`s[3] = '('`, so push `i = 3` onto the stack

* i = 4
Stack = [0,3] <-- TOP
Ans = 2

`s[4] = ')'`, so we pop off of the stack (`3`). Then, we update ans to be the max between itself and `i - stack.top() = 4 - 0 = 4`

* i = 5
Stack = [0] <-- TOP
Ans = 4

`s[5] = ')'`, so we pop off of the stack (`0`). Since the stack is empty now, then we push `i = 5` onto the stack

* Aftermath

We return 4, which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**