C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Keep track of the minimum cost to get to step `i - 1` and `i - 2` since those are the only values that matters. By the end, we know that the minimum cost is either found at `n - 1` or `n - 2`, which are held in the two variables

# Approach

Initialize 3 variables:

1. `two_steps_ago` holds the minimum cost for `i -2`
2. `last_step` holds the minimum cost for `i - 1`
3. `curr` is a temporary variable that holds `i`

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();

        int two_steps_ago = cost[0], last_step = cost[1], curr;
        for (int i = 2; i < n; i++) {
            curr = cost[i] + min(last_step, two_steps_ago);
            two_steps_ago = last_step;
            last_step = curr;
        }

        return min(last_step, two_steps_ago);
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**