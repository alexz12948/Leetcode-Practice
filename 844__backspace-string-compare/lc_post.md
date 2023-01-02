C++ || Easy to Understand with In-Depth Explanation and Examples || O(N + M)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)
  - [O(1) Space](#o1-space)

# TL;DR

Create two stacks to hold all of the characters. If we see a `#` character, then delete the top element of the stack. Return whether the two stacks are equal

## Code

```c++
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return createStack(s) == createStack(t);
    }
private:
    stack<char> createStack(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != '#')
                st.push(s[i]);
            else if (!st.empty())
                st.pop();

        return st;
    }
};
```

## Complexity

**Time Complexity:** $$O(N + M)$$ where $$N,M$$ is the size of each string
**Space Complexity:** $$O(N + M)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

The basic idea is that we use a stack and maintain what the string would look like. This is because as we read the string, if we see a `#` character, we know that the most recent character inputted would be removed. This *screams* stack since we always want the most recently inputted character from the string

## Approach 

In the original function, we just want to return if the two stacks that are generated from the strings are the same. For the creation of the stack, we iterate from front to back. 

If we see a character that isn't `#`, we push it onto the stack. Otherwise, as long as the stack isn't empty, we pop that element off.

## Example

Lets do an example where `s = "a##c"` and `t = "#a##c"`

**Creating the s stack**

* i = 0
Stack = [] <--(top)

The character is not `#`, so we push `a` onto the stack

* i = 1
Stack = [a] <--(top)

The character is `#` and the stack isn't empty, so we pop the top element off which is `a`

* i = 2
Stack = [] <--(top)

We encounter another `#`, but the stack is empty so we do nothing

* i = 3
Stack = [] <--(top)

The character is not `#`, so we push `c` onto the stack

* We return [c]

**Creating the t stack**

* i = 0
Stack = [] <--(top)

We encounter `#` first, but the stack is empty so we do nothing

* i = 1
Stack = [] <--(top)

The character is not `#`, so we push `a` onto the stack

* i = 2
Stack = [a] <--(top)

The character is `#` and the stack isn't empty, so we pop the top element off which is `a`

* i = 3
Stack = [] <--(top)

We encounter another `#`, but the stack is empty so we do nothing

* i = 4
Stack = [] <--(top)

The character is not `#`, so we push `c` onto the stack

* We return [c]

We return `true` since `[c] == [c]`

## O(1) Space

The idea is to iterate backwards in each string and compare as you go. I found a couple of solutions that would probably be better, plus I want to give credit where credit is due :)

* The cleanest code I found is [here](https://leetcode.com/problems/backspace-string-compare/solutions/135873/8-lines-c-o-1-space-easy-to-understand/?envType=study-plan&id=level-1&orderBy=most_votes)
* In general, this user always has nice solutions. Take a [look](https://leetcode.com/problems/backspace-string-compare/solutions/135603/java-c-python-o-n-time-and-o-1-space/?envType=study-plan&id=level-1&orderBy=most_votes)
* Though it is in Java, I found this person's code very easy to [read](https://leetcode.com/problems/backspace-string-compare/solutions/162827/java-two-pointer-with-explanation-beat-98/?envType=study-plan&id=level-1&orderBy=most_votes)

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**