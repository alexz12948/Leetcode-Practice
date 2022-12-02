Title: C++ || Easy to Understand with Explanation || Time O(N)
Tags: c++, easy-understanding, clean code

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!!** 🥺😁

### Intuition

We need to make a couple of observations about the solution;
we know that any 2 strings are close if:

1. **They both have the same length** --> Since the two operations are swapping and transforming (which is essentially replacing), there is no way to add more characters. Therefore, they must be the same length
2. **They have the same characters** --> If they don't have the same characters, then you cannot use the transform operation to make the strings close.

   For example, lets say `word1 = "x"` and `word2 = "y"`. Then there is no operation that can be performed to change the y into an x since by definition, we must "transform every occurance of one existing character into another **existing** character". Therefore, they must have the same characters in order to be close.
3. **They have the same frequencies** --> In order to use the transform operation effectively, both strings must have the frequency of characters in a string to be the same.

   For example, the last test case has `word1 = "cabbba"` and `word2 = "abbccc"`, we know that there is a characters with frequency of 1, 2, and 3. Since they both have the same frequencies of characters AND the same characters, we know that we can use the second operation to transform characters of one frequency to another character with the same frequency. In this case:
   * c can be transformed to be a; "c" --> "a"
   * a can be transformed to be b; "aa" --> "bb"
   * b can be transformed to be c; "bbb" --> "ccc"

### Approach

First, I want to check if the strings have the same length by
comparing their sizes. (Line 6)

Then, I want to get the frequencies of each of the characters
to be able to check condition 2 and 3 from the intuition. (Line 9-14)

Once we have the frequencies of each character, we need to check
that every character in `word1` exists in `word2`. This can be
achieved by checking if the frequency of a character in `word1`
has a nonzero value in `word2`. (Line 18-19)

Finally, we need to compare the frequencies from `word1` and `word2`
to ensure that condition 3 holds. This can be done with an
hash table (`unordered_map`) and just counting the frequencies.
Once we count all the frequencies, the two hash tables should
be the same in order for the strings to be close (Line 16 - 24)

### Complexity

**Time Complexity:** O(N) where N is the length of the strings
**Space Complexity:** O(N)

### Code

```c++
#define LOWERCASE_TO_NUMBER(c) (c - 'a')

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        const int len = word1.size();

        vector<int> word1_char_freq (26, 0), 
                    word2_char_freq(26, 0);
        for (int i = 0; i < len; i++) {
            word1_char_freq[LOWERCASE_TO_NUMBER(word1[i])]++;
            word2_char_freq[LOWERCASE_TO_NUMBER(word2[i])]++;
        }

        unordered_map<int,int> word1_freq_freq, word2_freq_freq;
        for (int i = 0; i < 26; i++) {
            if (word1_char_freq[i] == 0 && word2_char_freq[i] != 0) return false;
            if (word1_char_freq[i] != 0 && word2_char_freq[i] == 0) return false;
            word1_freq_freq[word1_char_freq[i]]++;
            word2_freq_freq[word2_char_freq[i]]++;
        }

        return word1_freq_freq == word2_freq_freq;
    }
};
```