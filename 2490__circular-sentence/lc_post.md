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

Make sure the first and last character **AND** the characters before and after spaces are equal

## Code

```c++
class Solution {
public:
    bool isCircularSentence(string sentence) {
        const int n = sentence.size();
        for (int i = 0; i < n; i++)
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return false;

        return sentence[0] == sentence[n - 1];
    }
};

```

## Complexity

**Time Complexity:** $$O(N)$$ where $$N$$ is the length of the string
**Space Complexity:** $$O(1)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

Iterate through the string and if we encounter a space, make sure that the character before equals the character after

## Approach 

I iterated through the characters in the string and if I came to a space, I checked if the character before did not equal the character after. If that is the case, I know the sentence is not circular and I can return false.

When that is finished, I just need to check if the first character is equal to the last character

## Example

Lets use the first example, where `sentence = "leetcode exercises sound delightful"`

I will be showing all of the checks, specifically at the spaces

| Space # | Char Before | Char After |
|:-------:|:-----------:|:----------:|
|    1    |      e      |      e     |
|    2    |      s      |      s     |
|    3    |      d      |      d     |

Since all of these are equal, I just check if `sentence[0] == sentence[n - 1]` $$\rightarrow$$ `'l' == 'l'`, so it returns true which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**