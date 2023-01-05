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

Count the number of vowels in the first half and second half and return if they are equal

## Code

```c++
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
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

Take a look at the [TL;DR](#tldr)

## Approach 

We just loop through the first half and second half of the string at the same time. We
also initialize 2 counter variables: one for the number of vowels in the first half
and another one for the number of vowels in the second half. We return whether or not the two counters are equal

## Example

Let's use the second example, where `s = "textbook"`

* i = 0
`vowel_count_first_half =  0`
`vowel_count_second_half = 0`

`s[i] = s[0] = 't'` and `t` is not a vowel so we do nothing
`s[i + half] = s[0 + 4] = 'b'` and `b` is not a vowel so we do nothing

* i = 1
`vowel_count_first_half =  0`
`vowel_count_second_half = 0`

`s[i] = s[1] = 'e'` and we increament the first counter
`s[i + half] = s[1 + 4] = 'o'` and we increament the second counter

* i = 2
`vowel_count_first_half =  1`
`vowel_count_second_half = 1`

`s[i] = s[2] = 'x'` and `x` is not a vowel so we do nothing
`s[i + half] = s[2 + 4] = 'o'` and we increament the second counter

* i = 3
`vowel_count_first_half =  1`
`vowel_count_second_half = 2`

`s[i] = s[3] = 't'` and `t` is not a vowel so we do nothing
`s[i + half] = s[3 + 4] = 'k'` and `k` is not a vowel so we do nothing

* Aftermath

Since `vowel_count_first_half != vowel_count_second_half`, we return `false` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**