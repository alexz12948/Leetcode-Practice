C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Use the original array to hold the running sum

## Code

```c++
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];

        return nums;
    }
};
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

Refer to the [TL;DR](#tldr)

## Approach 

The first index will just be itself, then from index 1 to n, it will be `nums[i] += nums[i - 1]` since you just want to add the previous value onto the current value continuously till the end. Then you just return the original array that was passed in.

## Example

Let's use the third example, where `nums = [3,1,2,10,1]`

* i = 1
`nums[i] += nums[i - 1]` $$\rightarrow$$ `nums[1] = nums[1] + nums[0] = 1 + 3 = 4`

* i = 2
`nums[i] += nums[i - 1]` $$\rightarrow$$ `nums[2] = nums[2] + nums[1] = 2 + 4 = 6` (remember we just updated `nums[i]` in the last bullet)

* i = 3
`nums[i] += nums[i - 1]` $$\rightarrow$$ `nums[3] = nums[3] + nums[2] = 10 + 6 = 16`

* i = 4
`nums[i] += nums[i - 1]` $$\rightarrow$$ `nums[4] = nums[4] + nums[3] = 1 + 16 = 17`

* Final Result = `[3,4,6,16,17]` which is the solution

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**