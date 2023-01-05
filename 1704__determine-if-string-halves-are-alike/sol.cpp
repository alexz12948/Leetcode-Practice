class Solution {
public:
    bool halvesAreAlike(string s) {
        const int half = s.size() / 2;
        unordered_set<char> vowels ({'a', 'e', 'i', 'o', 'u', 
                                     'A', 'E', 'I', 'O', 'U'});

        int vowel_count_first_half = 0, vowel_count_second_half = 0;
        for (int i = 0; i < half; i++) {
            if (vowels.count(s[i]) == 1) vowel_count_first_half++;
            if (vowels.count(s[i + half]) == 1) vowel_count_second_half++;
        }

        return vowel_count_first_half == vowel_count_second_half;
    }
};
