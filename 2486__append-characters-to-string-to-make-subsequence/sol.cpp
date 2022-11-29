/*
Explanation of Solution
-----------------------

To figure out how many characters to append, you need to figure out
the number of characters that do not exist in `s` in the order of `t`.

In other words, you need to determine the number of characters of `s`
that are in `t` in-order. Then, the number of characters that need to be
appended is the total characters in `t` minus the number of characters
that exist in order in `s`

Complexity
----------
Time: O(n) where n is the size of the first string
Space: O(1) 
*/
class Solution {
public:
    int appendCharacters(string s, string t) {
        const int n = s.size(), m = t.size();
        int tIdx = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[tIdx]) 
                tIdx++;
            if (tIdx == m)
                return 0;
        }

        return m - tIdx; 
    }
};
