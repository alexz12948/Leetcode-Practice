class Solution {
public:
    string frequencySort(string s) {
        const int n = s.size();

        unordered_map<char,int> freq;
        for (int i = 0; i < n; i++)
            freq[s[i]]++;

        vector<pair<char,int>> freq_arr(freq.begin(), freq.end());

        sort(freq_arr.begin(), freq_arr.end(), [](auto& f1, auto& f2) {
            return f1.second > f2.second;
        });

        string ans = "";
        for (pair<char,int> pair : freq_arr)
            while (pair.second-- > 0) ans += pair.first;

        return ans;
    }
};
