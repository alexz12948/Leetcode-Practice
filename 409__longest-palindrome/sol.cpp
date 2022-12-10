class Solution {
public:
    int longestPalindrome(string s) {
        const int n = s.size();
        unordered_map<char,int> freq;

        for (int i = 0; i < n; i++)
            freq[s[i]]++;

        int ans = 0;
        bool hasOdd = false;
        for (pair<char,int> f : freq) {
            ans += (f.second / 2) * 2;
            hasOdd |= f.second % 2 == 1;
        }

        return hasOdd ? ans + 1 : ans;
    }
};