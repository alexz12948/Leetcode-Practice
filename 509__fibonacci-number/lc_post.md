C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Iterate from 1 to n and at every index `i`, keep track of `i - 1` and `i - 2` since those are the only values that matter for the Fibonacci sequence

# Approach

First, we want to account for the base cases of `n == 0` and `n == 1`, where we just want to return `n`

Then, we know that `fib(0) = 0` and `fib(1) = 1`. Therefore we initialize 2 variables to hold fib `i - 1` (`first`) and fib `i - 2` (`second`). Then, we have `ans` to hold fib `i`.

We know `ans = first + second` since `fib(n) = fib(n - 1) + fib(n - 2)`. At the end, we just return `ans`

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        
        int first = 0, second = 1, ans;
        for (int i = 1; i < n; i++) {
            ans = second + first;
            first = second;
            second = ans;
        }

        return ans;
    }
};
```

## O(logN) Time Complexity Solution using Math

Take a look at [this](https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/) to see more information (look at method 7)

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**