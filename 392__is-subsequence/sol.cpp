class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int n = t.size();
        int s_idx = 0;
        for (int i = 0; i < n; i++)
            if (t[i] == s[s_idx])
                s_idx++;

        return s_idx == s.size();
    }
};