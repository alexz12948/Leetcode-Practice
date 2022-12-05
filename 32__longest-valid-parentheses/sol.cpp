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
