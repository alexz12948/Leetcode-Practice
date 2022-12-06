Title: C++ || Easy to Understand with In-Depth Explanation || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

An isomorphism is when you can map:
* Every character of s onto only one character in t
* Every character of t onto only one character in s

In other words, we need to make sure that in the example `s = "egg"` and `t = "add"` that:
* From $$s \rightarrow t$$, these characters map to each other: $$e \rightarrow a$$
* From $$t \rightarrow s$$, these characters map to each other: $$e \rightarrow a$$

We will be creating mappings of each character and ensuring for every character that there is a valid mapping for each character

# Approach

Create 2 unordered maps with the key value pair of `<char,char>`. One will be the mappings of the characters of $$s \rightarrow t$$ and the other will be the mappings of the characters in $$t \rightarrow s$$

For every character, we need to ensure that both maps either have a mapping or don't. For example if character `a` mapped to `b` from $$s \rightarrow t$$ and character `b` is mapped to `a` from $$t \rightarrow s$$, then we want to make sure that if character `a` is mapped, then character `b` must also be mapped. This is done using the first if conditional (`s_to_t_map.count(s[i]) ^ t_to_s_map.count(t[i]) == 1`). If you are unsure about how the xor operator works, take a look [here](https://cplusplus.com/doc/boolean/) and scroll to the xor section

Then, if there is a mapping, then we need to make sure that the values are mapped to the same character forwards and backwards. For example,
if `s = "babc"` and `t = "bada"`, then the first two characters would be fine, but the third character would get caught since `b` already maps to `b` from $$t \rightarrow s$$ (from index 0). This is done using the second if conditional

# Complexity

**Time Complexity:** $$O(n)$$
**Space Complexity:** $$O(n)$$

# Code

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int n = s.size();
        unordered_map<char,char> s_to_t_map;
        unordered_map<char,char> t_to_s_map;
        for (int i = 0; i < n; i++) {
            if (s_to_t_map.count(s[i]) ^ t_to_s_map.count(t[i]) == 1)
                return false;

            if (s_to_t_map.count(s[i]) == 1 && (s_to_t_map[s[i]] != t[i] || t_to_s_map[t[i]] != s[i]))
                return false;
                
            s_to_t_map[s[i]] = t[i];
            t_to_s_map[t[i]] = s[i];
        }

        return true;
    }
};
```