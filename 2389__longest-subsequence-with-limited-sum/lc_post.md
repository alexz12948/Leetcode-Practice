C++ || Easy to Understand with In-Depth Explanation and Examples || O(nlogn + mlogn)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Calculate the prefix sum and use binary search (`upper_bound`) to find the index of the greastest sum under the maximum sum

## Code

```c++
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        const int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());

        // Prefix Sum
        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];

        vector<int> ans(m);
        for (int i = 0; i < m; i++)
            ans[i] = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();

        return ans;
    }
};
```

## Complexity

**Time Complexity:** $$O(nlogn + mlogn)$$
**Space Complexity:** $$O(m)$$ for the answer array (otherwise $$O(1)$$)

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition



## Approach 



## Example



**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**