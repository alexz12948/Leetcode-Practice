class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int n = s.size();
        unordered_map<char,char> s_to_t_map;
        unordered_map<char,char> t_to_s_map;
        for (int i = 0; i < n; i++) {
            if (s_to_t_map.count(s[i]) ^ t_to_s_map.count(t[i]) == 1)
                return false;

            if (s_to_t_map.count(s[i]) == 1 && (s_to_t_map[s[i]] != t[i] || t_to_s_map[t[i]] != s[i]))
                return false;
                
            s_to_t_map[s[i]] = t[i];
            t_to_s_map[t[i]] = s[i];
        }

        return true;
    }
};