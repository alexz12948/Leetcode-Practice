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

1. Find all the bulls by iterating and use a hashtable to store the frequency of each character in `secret`
2. Count the number of characters in `guess` that are cows by using the hashtable to find the frequency of that character in `secret`

## Code

```c++
class Solution {
public:
    string getHint(string secret, string guess) {
        const int n = secret.size();
        unordered_map<char,int> secret_freq;
        int num_bulls = 0, num_cows = 0;

        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i])
                num_bulls++;
            else
                secret_freq[secret[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (secret[i] != guess[i] && secret_freq[guess[i]] > 0) {
                secret_freq[guess[i]]--;
                num_cows++;
            }
        }

        return to_string(num_bulls) + "A" + to_string(num_cows) + "B";
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

We need to separate the calculation of number of bulls from the calculation of the number of cows. The reason why is because we need to not double count digits that are "bull" digits. Therefore, we can just hold the frequency of all the digits in `secret` that are not bulls.

We first count the number of bull digits and keep track of the number of digits in `secret` that could be cows. Then we loop through the digits in `guess`. If there is a digit in `guess` that is not used for a bull digit in `secret`, then we can use that digit for a cow digit.

## Approach 

Initialize a frequency hashtable for the digits of `secret`. Then we iterate over all the characters in `secret`. If a digit at index `i` is the same between `guess` and `secret`, then we increament the number of bulls. Otherwise, we increase the frequency of that digit.

Next, we iterate over all the characters in `guess`. If a digit at index `i` is **NOT** the same between `guess` and `secret` **AND** there is at least 1 `guess[i]` character in `secret`, then we want to increase the number of cows by 1 and decrease the frequency of `guess[i]` character since we are now using it for a cow

At the end, we should have the number of bulls and cows

## Example

Let's use Example 2 where 
`secret = "1123"` and 
`guess =  "0111"`

First, we find the number of digits in the right location (a bull digit) and keep track of the frequency of the characters in `secret` that are not used. At the end, we should have:

`secret_freq = {('1': 1), ('2': 1), ('3': 1)}` and `num_bulls = 1` since there is one character that lines up

Then, we make sure the characters are not the same and check if there is a character in `secret` that also exists in `guess` as we iterate. For example, as we iterate through `guess` and we are at index `2`, there is a `'1'` in `secret` that is not a bull, so we can increase the number of cows and decrease that character's frequency since it was used for the cow

At the end, we have 1 bull and 1 cow so `"1A1B"`

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**