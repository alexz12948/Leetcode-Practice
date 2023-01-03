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

Create a map of every character in `s` and `t` to an index (1-indexed) and ensure that the indicies are the same as we iterate through the strings

## Code

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int n = s.size();
        unordered_map<char,int> s_to_t_map;
        unordered_map<char,int> t_to_s_map;
        for (int i = 0; i < n; i++) {
            if (s_to_t_map[s[i]] != t_to_s_map[t[i]])
                return false;
                
            s_to_t_map[s[i]] = t_to_s_map[t[i]] = i + 1;
        }

        return true;
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

An isomorphism is when you can map:
* Every character of s onto only one character in t
* Every character of t onto only one character in s

In other words, we need to make sure that in the example `s = "egg"` and `t = "add"` that:
* From $$s \rightarrow t$$, these characters map to each other: $$e \rightarrow a$$
* From $$t \rightarrow s$$, these characters map to each other: $$e \rightarrow a$$

BUT opposed to mapping $$char \rightarrow char$$, we will map $$char \rightarrow int$$ since it will keep the same functionality

## Approach 

Create 2 unordered maps with the key value pair of `<char,int>`. One will be the mappings of the characters of $$s \rightarrow index$$ and the other will be the mappings of the characters in $$t \rightarrow index$$

For every character, we check the maps to ensure that they have the same index. If they don't, then we know that there is not a bijection from $$s \leftrightarrow t$$ so we return false. Note that when we use `unordered_map` and the `[]` operator, if a key doesn't exist in a table yet, it will automatically create the key value pair and initialize the value to `0` since we are dealing with integers. We want this behavior since we are storing all of the mappings using 1-indexing and `0` would indicate that a character has not been mapped yet

Otherwise, we update the map to have the index `i + 1` since we want to keep track of the latest value

## Example

Lets use the second example, where `s = "foo"` and `t = "bar"`

* i = 0

`s_to_t_map['f']` and `t_to_s_map['b']` will have the same value of `0` since neither character has been mapped yet

We then assign both of them to have the value `1`: `s_to_t_map['f'] = t_to_s_map['b'] = 1`

* i = 1

`s_to_t_map['o']` and `t_to_s_map['a']` will have the same value of `0` since neither character has been mapped yet

We then assign both of them to have the value `2`: `s_to_t_map['o'] = t_to_s_map['a'] = 2`

* i = 2

`s_to_t_map['o'] = 2` from the previous iteration but `t_to_s_map['r'] = 0` since it hasn't been mapped yet. Since these two values are different, it shows that there is not a bijection since `'o'` would be mapped two 2 different characters in `t` (mapped to both `'a'` and `'r'`), so we return false

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**