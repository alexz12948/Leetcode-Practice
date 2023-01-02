C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Determine whether all the characters from the second charater onward is all lowercase or all uppercase. There are 2 cases: 
* If the first letter is uppercase --> either all the other characters need to be lowercase or uppercase
* If the first letter is lowercase --> all other characters must be lowercase.

## Code

```c++
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
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We can think about this problem as breaking it into 3 cases:
1. All characters are lowercase
2. All characters are uppercase
3. Only first character is uppercase and the rest is lowercase

However, we can notice that the last case pretty much the information we calculated in the first case except for the first character. 

Therefore, if we just figure out if the characters from the second character till the end is either all uppercase or all lowercase. Then, if the first character is uppercase, then we check if all the characters are uppercase (case 2) **OR** all the characters are lowercase (case 3). If the first character is lowercase, then check if all the characters are lowercase (case 1).

## Approach 

Initialize 2 boolean variables to `true`. Then, use macros and check if each character is either lowercase or uppercase from `i = 1` to `i = n - 1`. Update the cooresponding variable as needed.

Then, use a ternary operator to see if the first character is uppercase. If it is, then return whether all the characters (`i = 1 to n - 1`) are lowercase or all characters are uppercase. If not, then return whether all characters are lowercase.

## Example

Lets use the second example provided, where `word = "FlaG"`

First, we initialize the two booleans to be true. Then, we iterate and determine whether all the characters from `i = 1 to n - 1` are lowercase or uppercase.

When `i = 1`, `all_uppercase` will be set to `false` since `word[1] = 'l'`

When `i = 3`, `all_lowercase` will be set to `false` since `word[3] = 'G'`

We know the first character is uppercase, so we return `all_uppercase | all_lowercase`. Since both are false, we return `false` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**