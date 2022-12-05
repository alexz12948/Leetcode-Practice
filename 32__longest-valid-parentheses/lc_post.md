Title: C++ || Easy to Understand with In-Depth Explanation || O(N)
Tags: cpp, c++, easy-understanding, clean code, beginner, beginner friendly, easy, stack

### PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

### Intuition

All we want to do is scan the string from start to finish and use a stack to figure out if the index we are still looking at is valid

In other words, we want to push the indices of the opening brackets and if you encounter a closing bracket, then we calculate how long was this valid parenthesis (assuming that the stack is not empty) and update the ans if it is longer than the current best

### Approach

This is a modified version of the valid parenthesis problem

We initially push `-1` onto the stack because it is to indicate the last location of a valid parenthesis. At first, the last valid parenthesis finished at index `-1`. Then, every time we encounter an opening bracket, we want to push that onto the stack too. 

If it isn't an opening bracket (aka closing bracket), we want to pop off the stack. If the stack is not empty, that means we have encountered a valid parenthesis and the stack's current top is the position before the start of the valid string. Therefore, taking the difference between the current index and the stack's top will yield the length of the valid string and we update the answer if it is longer than the current best.

If the stack is empty, that means that we have no idea where the next valid parenthesis set is (since we always compare it to the stack's top element). Therefore, we just push the current index onto the stack to indicate the location of the last valid parenthesis.

### Complexity

**Time Complexity:** O(n)
**Space Complexity:** O(n)

### Code

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