C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

We know that there has to be two paths that the frog must take: one from `stones[0]` to `stones[n - 1]` and another one from `stones[n - 1]` to `stones[0]`

We just need to decide whether or not the stone belongs to the first path or the second path.

By observation, we need to assign the stones in an alternating fashion to the paths. Here is an example: lets say there are 4 stones. If the frog doesn't take alternating stones (aka the frog goes from the first stone to the last stone) then we know that that jump would be greater than jumping to the third stone and then the fourth stone. Therefore, we want to always altnerate

The only special case we need to consider is if there is only 2 stones, which means that we just return the difference between those stones.

# Approach

Find the maximum of all of the jumps that skip a stone

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans = stones[1] - stones[0];
        for (int i = 2; i < stones.size(); i++)
            ans = max(ans, stones[i] - stones[i - 2]);

        return ans;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**