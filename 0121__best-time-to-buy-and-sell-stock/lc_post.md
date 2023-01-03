Title: C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

We want to keep track of the current minimum that was seen because that is the point where you would want to possibly buy. Then, the answer is just the maximum between the prices and the current minimum

# Approach

We initialize the current minimum to be `INT_MAX` since we want the minimum to get updated. Then, we just continuously update the current minimum with the current price if necessary and update the answer if the difference between the current day's price and the current minimum is greater than the current best answer

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();

        int ans = 0, curr_min = INT_MAX;
        for (int i = 0; i < n; i++) {
            curr_min = min(curr_min, prices[i]);
            ans = max(ans, prices[i] - curr_min);
        }

        return ans;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**