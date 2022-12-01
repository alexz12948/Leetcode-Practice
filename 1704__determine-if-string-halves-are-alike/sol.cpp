class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

public:
    bool halvesAreAlike(string s) {
        const int n = s.size(), half = n / 2;

        int vowel_count_first_half = 0, vowel_count_second_half = 0;
        for (int i = 0; i < half; i++) {
            if (isVowel(s[i])) vowel_count_first_half++;
            if (isVowel(s[i + half])) vowel_count_second_half++;
        }

        return vowel_count_first_half == vowel_count_second_half;
    }
};
