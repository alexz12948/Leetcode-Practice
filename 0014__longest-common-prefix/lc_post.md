C++ || O(N + M) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Find the smallest and largest strings and compare them to determine the size of the prefix

## Code

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];

        string smallest = *min_element(strs.begin(), strs.end()), 
               biggest = *max_element(strs.begin(), strs.end());

        for (int i = 0; i < smallest.size(); i++)
            if (smallest[i] != biggest[i])
                return smallest.substr(0, i);

        return smallest;
    }
};
```

## Complexity

**Time Complexity:** $$O(N + maxM)$$ where $$N$$ is the number of strings and $$maxM$$ is the largest string in the array
**Space Complexity:** $$O(1)$$ 

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

Before anything, if there is only 1 string, then we just return that string since there is nothing to compare it with

Then, we want to find the strings that are most different which would be the smallest and largest string. Compare every character of the smaller string to the larger string. If they do not match at index `i`, then take the first `i` elements from the smallest string. If they match at every character, then just return the smaller string

## Approach 

First, we check the number of strings since if there is only 1, we want to just return `strs[0]`

Then, we use the STL `min_element` and `max_element` to find the smallest and largest element in the array. To read more about these functions, take a look [at this stackoverflow post](https://stackoverflow.com/questions/72921545/how-do-min-element-work-with-string-array-and-maybe-with-vector-strnig-array). Additionally, one could use `minmax_element()` which has the same parameters as `min_element` and `max_element` but returns a pair of iterators. I found those hard to read syntactially, but it does exist for those who are looking for **efficiency** 😈

Compare every character of `smallest` to `largest`. If they do not match at index `i`, then take the first `i` elements from `smallest` (`smallest.substr(0, i)`). If they match at every character, then just return `smallest` since it must be the longest prefix of all strings

## Example

Lets use the first example, where `strs = ["flower","flow","flight"]`

The min element is `flight` and the max element is `flower` since `flight` has the smallest

Then we loop through the characters of `flight` and determine where the prefix ends.

| i | `min_elem[i]` | `max_elem[i]` | Match? |
|:-:|:-------------:|:-------------:|:------:|
| 0 |       f       |       f       |   yes  |
| 1 |       l       |       l       |   yes  |
| 2 |       i       |       o       |   no   |

Therefore, we do `smallest.substr(0, i) == smallest.substr(0, 2) == "fl"` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**