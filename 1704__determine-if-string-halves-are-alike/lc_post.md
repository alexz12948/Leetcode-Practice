Title: C++ || Easy to Understand with Explanation
Tags: c++, easy-understanding, clean code, string

### Intuition

The basic intuition is to do exactly what it is asking for: count all of the vowels
in the first half and compare it to the number of vowels in the second half

### Approach

We just loop through the first half and second half of the string at the same time. We
also initialize 2 counter variables: one for the number of vowels in the first half
and another one for the number of vowels in the second half. We just need to return
whether the 2 counts are equal after the loop ends to have our answer

### Complexity

Time Complexity: O(n) where n is the length of the string
Space Complexity: O(1)

### Code

```c++
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
public:
    bool halvesAreAlike(string s) {
        const int half_len = s.size() / 2;

        int vowel_count_first_half = 0, vowel_count_second_half = 0;
        for (int i = 0; i < half_len; i++) {
            if (isVowel(s[i])) vowel_count_first_half++;
            if (isVowel(s[i + half_len])) vowel_count_second_half++;
        }

        return vowel_count_first_half == vowel_count_second_half;
    }
};
```