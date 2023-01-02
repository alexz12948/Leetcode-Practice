class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return createStack(s) == createStack(t);
    }
private:
    stack<char> createStack(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != '#')
                st.push(s[i]);
            else if (!st.empty())
                st.pop();

        return st;
    }
};