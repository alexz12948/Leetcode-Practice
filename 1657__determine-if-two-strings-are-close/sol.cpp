#define LETTER_INDEX(c) (c - 'a')

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        const int len = word1.size();

        vector<int> word1_char_freq (26, 0), 
                    word2_char_freq(26, 0);
        for (int i = 0; i < len; i++) {
            word1_char_freq[LETTER_INDEX(word1[i])]++;
            word2_char_freq[LETTER_INDEX(word2[i])]++;
        }

        unordered_map<int,int> word1_freq_freq, word2_freq_freq;
        for (int i = 0; i < 26; i++) {
            if ((bool)word1_char_freq[i] ^ (bool)word2_char_freq[i] == 1) return false;
            word1_freq_freq[word1_char_freq[i]]++;
            word2_freq_freq[word2_char_freq[i]]++;
        }

        return word1_freq_freq == word2_freq_freq;
    }
};
