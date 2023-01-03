C++ || O(N) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

* If the words aren't the same size, return `false`
* Find the frequency of the characters in each string
* If one string has a character that the other doesn't, return `false`
* Find the frequencies of all of the frequencies
* Return whether the frequencies of frequencies are the same

## Code

```c++
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
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We need to make a couple of observations about the solution; we know that any 2 strings are close if:

1. **They both have the same length** --> Since the two operations are swapping and transforming (which is essentially replacing), there is no way to add more characters. Therefore, they must be the same length
2. **They have the same characters** --> If they don't have the same characters, then you cannot use the transform operation to make the strings close.

   For example, lets say `word1 = "x"` and `word2 = "y"`. Then there is no operation that can be performed to change the y into an x since by definition, we must "transform every occurance of one existing character into another **existing** character". Therefore, they must have the same characters in order to be close.
3. **They have the same frequencies** --> In order to use the transform operation effectively, both strings must have the frequency of characters in a string to be the same.

   For example, the last test case has `word1 = "cabbba"` and `word2 = "abbccc"`, we know that there is a characters with frequency of 1, 2, and 3. Since they both have the same frequencies of characters AND the same characters, we know that we can use the second operation to transform characters of one frequency to another character with the same frequency. In this case:
   * c can be transformed to be a; "c" $$\rightarrow$$ "a"
   * a can be transformed to be b; "aa" $$\rightarrow$$ "bb"
   * b can be transformed to be c; "bbb" $$\rightarrow$$ "ccc"

## Approach 

First, I want to check if the strings have the same length by comparing their sizes. (Line 6)

Then, I want to get the frequencies of each of the characters to be able to check condition 2 and 3 from the intuition. (Line 9-14)

Once we have the frequencies of each character, we need to check that every character in `word1` exists in `word2`. This can be achieved by checking if the frequency of a character in `word1` has a nonzero value in `word2`. This can be accomplished by using the xor operator on booleans (look at the table below) (Line 18)

![xor boolean table](https://www.baeldung.com/wp-content/uploads/2019/08/xor_operator_table-1.png)

Finally, we need to compare the frequencies from `word1` and `word2` to ensure that condition 3 holds. This can be done with an hash table (`unordered_map`) and just counting the frequencies. Once we count all the frequencies, the two hash tables should be the same in order for the strings to be close (Line 16 - 24)

## Example

Let's use the third example, where `word1 = "cabbba"` and `word2 = "abbccc"`

They are the same length, so we can continue

* Character Frequency

I will not go over this directly, but here is what they would look like:
`word1 = [{c: 1, a: 2, b: 3}]`
`word2 = [{a: 1, b: 2, c: 3}]`

* Frequency of Frequencies

Then we want to determine the number of times a certain frequency appears. Here is what that would look like:
`word1 = [{1: 1, 2: 2, 3: 3}]`
`word2 = [{1: 1, 2: 2, 3: 3}]`

Since they are the same, we would return `true` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**