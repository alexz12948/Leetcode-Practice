C++ || Easy to Understand with In-Depth Explanation and Examples || O(TODO)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

1. Precompute the total sum of all elements in the array
2. Iterate through array and determine if `i` is the pivot index

## Code

```c++
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int n = nums.size();
        int ans = -1, totalSum = 0, currSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += nums[i];

        for (int i = 0; i < n; i++) {
            totalSum -= nums[i];
            if (totalSum == currSum) {
                ans = i;
                break;
            }

            currSum += nums[i];
        }

        return ans;
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

Go through the algorithm like they described, but pre-compute the total sum of the entire array and use that to your advantage while trying to compute the pivot index. Notice that for any pivot index `i` that you are checking, notice that the left sum is the current running sum to index `i - 1` and the right sum is the `total` sum minus the values from index 0 to i. For example, in example 1 with input `[1,7,3,6,5,6]`, with a pivot index of 3. The left sum is the running sum from 0 to i - 1 (`nums[0] + nums[1] + nums[2]`) and the right sum is equal to (`total - nums[0] - nums[1] - nums[2] - nums[3]` where total is the sum of all indices)

## Approach 

Initialize the answer to be `-1` since we do not know whether there is an answer in the array. Then, you find the sum of all the elements in `nums` and keep it in a variable. Then, we initialize the current sum to be 0. 

Finally, we want to iterate over the original array again, but this time, we subtract the pivot index's value (`total -= nums[i]`) and then check if the left sum equals the right sum. If it does, we found our answer and we exit the iteration. If it doesn't, then we just add the current pivot index's value to the running sum since we are about to iterate over to the next value and we know that index `i` is not the pivot index.

## Example

Lets use the example 1, where `nums = [1,7,3,6,5,6]`

We precompute that the total sum is 28 and note that for the table, all of these values are inputted **when the conditional happens** (aka after the subtraction from `total_sum` but before the addition to `curr_sum`)

| i | curr_sum | total_sum | is_equal? |
|---|----------|-----------|-----------|
| 0 | 0        | 27        | False     |
| 1 | 1        | 20        | False     |
| 2 | 8        | 17        | False     |
| 3 | 11       | 11        | True      |

Which yields `i = 3` and is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**