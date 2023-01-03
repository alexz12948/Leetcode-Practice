C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)
    - [Example 1 - Strings Equal](#example-1---strings-equal)
    - [Example 2 - Strings Not Equal](#example-2---strings-not-equal)

# TL;DR

Break the problem into its individual cases and solve each one:

* If the strings are not equal length, return `false`
* If the string are the same: check if there is a character with a frequency >1 so that we can just swap those
* If the strings aren't the same: check to see if they differ in AT MOST 2 locations

## Code

```c++
#define LOWERCASE_TO_INDEX(c) (c - 'a')

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        const int n = s.size();
        if (n != goal.size()) return false;

        if (s == goal) {
            vector<int> char_freq(26, 0);

            for (int i = 0; i < n; i++)
                if (++char_freq[LOWERCASE_TO_INDEX(s[i])] > 1)
                    return true;

            return false;
        }

        int first_diff_idx = -1, second_diff_idx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != goal[i]) {
                if (first_diff_idx == -1)
                    first_diff_idx = i;
                else if (second_diff_idx == -1)
                    second_diff_idx = i;
                else 
                    return false;
            }
        }

        return second_diff_idx != -1 && 
               s[first_diff_idx] == goal[second_diff_idx] && 
               s[second_diff_idx] == goal[first_diff_idx];
    }
};
```

## Complexity

**Time Complexity:** $$O(N)$$ where $$N$$ is the length of the string
**Space Complexity:** $$O(1)$$ since the frequency array is the only thing initialized and it has a constant size

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

The basic idea that I followed is breaking it up into 2 cases:
1. If the strings aren't the same length
2. If the strings are equal
3. If the strings aren't equal

### Case 1: Not Equal Length <!-- omit from toc -->
If the strings aren't equal, there is no way to get a buddy strings using the swap operation, so we just return false

### Case 2: Equal Strings <!-- omit from toc -->
If the strings are equal, then we need to determine if there is a character with a frequency of >1. If that is the case, then we can swap the same character and still have buddy strings.

For example, if s = "aba" and goal = "aba", then you could swap the two 'a' characters to then have buddy strings. Remember that you MUST swap at least once

### Case 3: Not Equal Strings <!-- omit from toc -->
If the strings aren't equal, we want to figure out if they differ in only 2 locations and where those locations are. If they differ in more than 2 locations, then they can't be buddy strings. If they only differ in two locations, we need to ensure that if we swap those characters that the strings would be equal.

## Approach 

We want to break it up by checking if the strings are equal since we need two different approaches for those two cases.

If the strings are equal, then I used a frequency array to keep track of the frequency of letters. If I encounter a character that has occured more than once, then I return true since we could just swap those characters. If we do not find any character with a frequency of more than 1, then return false.

If the strings aren't equal, then I want to find the locations where the two strings differ using 2 pointers. The first time that they differ, I store the index in the first pointer. The second time that they differ, I store the index in the second pointer. If they differ more than that, I know that the strings cannot be equal by swapping only 2 characters, so I return false. At the end of the iteration, I have to see if there were two differences (`second_diff_idx != -1`) and that the locations where they differ have
the same character in each of them so the swap could be done and have equal strings afterwards (`s[first_diff_idx] == goal[second_diff_idx] && s[second_diff_idx] == goal[first_diff_idx]`)

### Tricky Portion of Code <!-- omit from toc -->

```c++
if (++char_freq[LOWERCASE_TO_INDEX(s[i])] > 1)
```

On line 13, I used this to shorter my code. Notice that I am using a macro named `LOWERCASE_TO_INDEX` to convert the lowercase letter to an index in the frequency array. Also, since I am using the pre-pended `++` operator, it adds 1 to the value prior to doing the comparison. That way, if the character has been seen before, it must have a value of 1 before this statement. Then, it will be increamented to 2 prior to the comparison, which is exactly what we want. Please follow up below if this was confusing to you!

## Example

Lets do 2 different examples since there are 2 cases to consider:

### Example 1 - Strings Equal

Lets use an example where `s = "aba"` and `t = "aba"`. Since `s == t`, we enter the equal case.

We find the frequency of all the characters in one of the strings since they are the same. In our case, we have `'a' = 2` and `'b' = 1`.  Since the frequency of `'a'` is >1, we could swap those characters to keep them buddy strings so we return `true`

### Example 2 - Strings Not Equal

Lets use an example where `s = "abb"` and `t = "bba"`. We must iterate through all the characters.

* i = 0

`s[i] != goal[i]`, so we update `first_index = 0`

* i = 1

`s[i] == goal[i]` so we don't do anything and continue

* i = 2

`s[i] != goal[i]` so we update `second_index = 2` since `first_index` was already mapped

* Aftermath

We know that they only differ in two locations, so we need to check if `s[0] == t[2]` and `s[2] == t[0]`: `s[0] = t[2] = 'a'` and `s[2] = t[0] = 'b'`, so we return `true`

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**