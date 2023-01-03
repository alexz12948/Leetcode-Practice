C++ || Easy to Understand with In-Depth Explanation and Examples || O(M)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Keep track of the index of the last mapping of `pattern[i]` to word. If the mapping's indices aren't the same, return `false`. Otherwise, update the mapping. At the end, make sure that the number of words read matches the pattern's length

## Code

```c++
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        const int n = pattern.size();
        istringstream ss(s);

        unordered_map<char,int> char_map;
        unordered_map<string,int> word_map;
        
        int i = 0;
        for (string word; ss >> word; i++) {
            if (char_map[pattern[i]] != word_map[word])
                return false;
            char_map[pattern[i]] = word_map[word] = i + 1;
        }

        return i == n;
    }
};
```

## Complexity

**Time Complexity:** $$O(M)$$ where $$M$$ is the number of words in `s`
**Space Complexity:** $$O(M)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We want to ensure that every letter in `pattern` matches up once and only once to every word in `s`. In order to do this, we need to determine if there is a bijection from $$pattern \rightarrow s$$ and $$s \rightarrow pattern$$

We do this by keeping track of the last mapped location of `pattern[i]` and the associated word. If they are the same, that means that they map together and we update the most recent location, but if they aren't equal then we know that either `pattern[i]` doesn't map to the most recent word or vice versa

## Approach 

We initialize a string stream (`istringstream`) to parse `s` into individual words, 2 maps (one for the characters in `pattern` and the other for words in `s`)

Then, we continuously read in words and check if the mapping is the same. If it isn't return false. Otherwise, update the map to be `i + 1`. We do this because if an element doesn't exist in an unordered_map and we use the `[]` operator, then it automatically initializes the key value pair. In this case, the default value would be 0, so we want to store the 1-indexed value so the default behaivor is ok

At the end, we just want to ensure that we read in the same number of words that the pattern has.

## Example

Lets use the second example, where `pattern = "abba"` and `s = "dog cat cat fish"`

* i = 0, word = "dog"

`char_map['a']` and `word_map["dog"]` will have the same default value of `0` since it doesn't exist in the map yet so it passes the check

Then `char_map['a'] = word_map["dog"] = 1` (i + 1 --> 0 + 1 = 1)

* i = 1, word = "cat"

`char_map['b']` and `word_map["cat"]` will have the same default value of `0` since it doesn't exist in the map yet so it passes the check

Then `char_map['b'] = word_map["cat"] = 2`

* i = 2, word = "cat"

`char_map['b'] = word_map["cat"]` since they both have the value of 2, so we don't return false.

Then `char_map['b'] = word_map["cat"] = 3` since we want to update it to have the most recent location

* i = 3, word = "fish"

`char_map['a']` and `word_map["fish"]` have different values since `char_map['a'] = 1` from the first iteration and `word_map["fish"] = 0` since it hasn't been inserted into the map before and return `false`

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**