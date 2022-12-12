C++ || 3 Line Solution || Easy to Understand with In-Depth Explanation and Examples || O(logN)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition and Approach

There are plenty of really good explanations with animations, which I will link here:

* [Post 1](https://leetcode.com/problems/binary-search/solutions/423162/binary-search-101/?envType=study-plan&id=level-1&orderBy=most_votes)
* [Post 2](https://leetcode.com/problems/binary-search/solutions/1322419/5-variations-of-binary-search-a-self-note/?envType=study-plan&id=level-1&orderBy=most_votes)

However I am here to show the code for the 2 line solution and the normal solution

# Complexity

**Time Complexity:** $$O(logN)$$
**Space Complexity:** $$O(1)$$

# Normal Code

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }
};
```

# 3 Line Solution Code

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target) return -1;
        return it - nums.begin();
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**