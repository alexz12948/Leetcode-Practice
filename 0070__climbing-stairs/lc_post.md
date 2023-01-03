C++ || O(N) Space AND O(1) Space || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

We can determine the number of ways to climb the `x` steps by determining how to climb `x - 1` steps + `x - 2` steps.

The intuition is that if you know how to climb `x - 1` steps, then the only way to climb `x` steps is to climb one more step. The only way to climb `x - 2` steps is to climb two more steps (because if we say that we can climb one step then one step, we double count the `x - 1` step)

This is a simple DP problem which can be solved with either $$O(N)$$ space of $$O(1)$$ space, and I will show both below

# Array Approach

We initialize an array with n elements and we account for the base cases of whether `n == 1` or `n == 2`. Once that is finished, we loop from 3 to n and return `dp[n - 1]` since that will return the number of ways to climb `n` steps. *Note that in the code, since I used everything 0 index'ed, I needed to subtract 1 off most of the constants*

# Array Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

# Array Code

```c++
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) 
            return 1;
            
        int dp[n];
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n - 1];
    }
};
```

# Variable Approach

We can optimize this approach since we only need 3 variables: one for `x - 2`, one for `x - 1`, and the final one for the answer. We perform the same process, but using the variables oppossed to storing all n elements since we don't care about the values from 3 steps below the current step and before.

# Variable Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

# Variable Code

```c++
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) 
            return n;

        int two_before = 1, one_before = 2, ans;
        for (int i = 2; i < n; i++) {
            ans = one_before + two_before;
            two_before = one_before;
            one_before = ans;
        }

        return ans;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**