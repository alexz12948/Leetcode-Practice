class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n = s.size(), m = p.size();
        if (m > n)
            return {};

        unordered_map<char,int> p_freq, s_freq;
        vector<int> ans;
        for (int i = 0; i < m; i++)
            p_freq[p[i]]++;

        for (int i = 0; i < n; i++) {
            s_freq[s[i]]++;
            if (i >= m)
                if (--s_freq[s[i - m]] == 0)
                    s_freq.erase(s[i - m]);

            if (s_freq == p_freq)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};