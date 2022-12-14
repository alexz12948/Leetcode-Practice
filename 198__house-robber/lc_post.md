C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Use bottom up DP with 2 variables. We only need to keep track of the best robbing amount for the house before and the house 2 before. We pretty much just need to decide whether we are going to rob house `i` or not. If we rob house `i` then we take the money in house `i` and the money in house `i - 2`. If we decide not to rob house `i`, then we rob house `i - 1` since we want the greatest total.

# Approach

Initialize 2 variables to store the best robbing amount for the previous house and the house 2 houses ago. Then,
we want to grab the max between robbing house `i` and house `i - 2` or robbing house `i -1`

At the end, we want to return `prev_house` since it will hold the maximum of robbing house `n`

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();

        int prev_house = 0, prev_2_house = 0;
        for (int i = 0; i < n; i++) {
            int tmp = prev_house;
            prev_house = max(prev_2_house + nums[i], prev_house);
            prev_2_house = tmp;
        }

        return prev_house;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**