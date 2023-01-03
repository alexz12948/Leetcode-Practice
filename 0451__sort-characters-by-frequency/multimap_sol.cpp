class Solution {
public:
    string frequencySort(string s) {
        const int n = s.size();

        unordered_map<char,int> freq;
        for (int i = 0; i < n; i++) 
            freq[s[i]]++;

        multimap<int,char,greater<int>> reverse_freq_map;
        for (auto pair : freq)
            reverse_freq_map.insert(make_pair(pair.second, pair.first));
      
        string ans = "";
        for (pair<int,char> pair : reverse_freq_map)
            ans += string(pair.first, pair.second);

        return ans;
    }
};
