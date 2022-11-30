/*
Explanation of Solution
-----------------------

This is a modified version of the valid parenthesis
problem

The basic idea is that you want to be pushing the indices
of the opening brackets and if you encounter a closing
bracket, then you want to figure out the difference between
the values assuming that the stack is not empty.

If the stack is empty, that means that we would have no
idea whether or not the next valid parenthesis is. We use
the stacks top value after it gets popped off to determine
how long the string actually was (since if char != '(', then
idx will get popped off which is ideally the opening bracket)

Complexity
----------
Time: O(n)
Space: O(n) 
*/

#define OPEN_BRACKET '('
#define CLOSE_BRACKET ')'

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
