class Solution {
public:
    bool wordPattern(string pattern, string s) {
        const int n = pattern.size();
        istringstream ss(s);

        unordered_map<char,int> char_map;
        unordered_map<string,int> word_map;
        
        int i = 0;
        for (string word; ss >> word; i++) {
            if (char_map[pattern[i]] != word_map[word])
                return false;
            char_map[pattern[i]] = word_map[word] = i + 1;
        }

        return i == n;
    }
};