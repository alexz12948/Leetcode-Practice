Title: C++ || Easy to Understand with In-Depth Explanation || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

The basic idea is that you want to use a stack that holds values in decreasing values otherwise known as a decreasing monotonic stack

# Approach

Opposed to using a traditional stack, I am going to use a string since it has all the operations that I would need from a stack but it would just allow me to not have to move all the elements off of a stack and put them into a string at the end (might as well use what I have from the beginning!)

First, we iterate through all of the characters and if the queue is not empty OR the character is not a '0', then we push it onto the stack. The reason for this logic is to prevent adding leading zeros to the solution.

As we iterate, we need to maintain a decreasing monotonic stack. In order to do that, we need to check if the top of the stack's value is greater than the current character that we are looking at. If so, then we pop the value off of the top and count that digit as removed (`k--`). We just need to ensure that we still have characters to pop off, which comes from the check `k > 0` in the while loop condition.

The second while loop outside of the normal iteration is for a case where there is a substring that is increasing and we can still pop values off. What happens is that while there are still values to pop off the stack and we can still remove characters from the string, we pop the back values off since they must have been increasing.

At the end, if the answer string is empty, then we just return 0 since we can remove all the characters. Otherwise, we just return the answer string

# Complexity
- Time complexity:
$$O(N)$$ where N is the length of the string

- Space complexity:
$$O(N)$$ for the answer

# Code
```
class Solution {
public:
    string removeKdigits(string num, int k) {
        const int n = num.size();
        string ans;

        for (char c : num) {
            while (!ans.empty() && ans.back() > c && k > 0) {
                ans.pop_back();
                k--;
            }

            if (!ans.empty() || c != '0')
                ans.push_back(c);
        }

        while (k > 0 && !ans.empty()) {
            k--;
            ans.pop_back();
        }

        return ans == "" ? "0" : ans;
    }
};
```