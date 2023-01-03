#define IS_LOWERCASE(c) ((c) >= 'a' && (c) <= 'z')
#define IS_UPPERCASE(c) ((c) >= 'A' && (c) <= 'Z')

class Solution {
public:
    bool detectCapitalUse(string word) {
        const int n = word.size();
        bool all_lowercase = true, all_uppercase = true; 

        // Note that it is from i = 1 opposed to i = 0
        for (int i = 1; i < n; i++) {
            all_lowercase &= IS_LOWERCASE(word[i]);
            all_uppercase &= IS_UPPERCASE(word[i]);
        }

        return IS_UPPERCASE(word[0]) ? all_uppercase | all_lowercase
                                     : all_lowercase;
    }
};