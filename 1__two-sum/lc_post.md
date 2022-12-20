C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Use a hashtable to keep track of all the values that we have seen. Then, we know that for every integer as we are interating at index `i` is looking for its complement. For example, if the target is `10` and the number at index `i` is `7`, then the matching complement would be `3` since `10 - 7 = 3`. 

In other words, we want to determine if the complement of the current number exists inside of the array. When we find a number and its complement relative to the target, then we have found the solution.

# Approach

Create a hashtable where the key is a value in the array and the value is the index (since we need to return a vector with the two indices)

# Example

Lets use Example 2 where `nums = [3,2,4]` and `target = 6`

### i = 0
**Map:** `{}`

We check to see if the complement `target - nums[i] = 6 - 3 = 3` exists in the map. Since there is nothing, then we just insert the pair `(3, 0)` into the map

### i = 1
**Map:** `{(3,0)}`

We check to see if the complement `target - nums[i] = 6 - 2 = 4` exists in the map. Since it doesn't, then we just insert the pair `(2, 1)` into the map

### i = 2
**Map:** `{(3,0), (2,1)}`

We check to see if the complement `target - nums[i] = 6 - 4 = 2` exists in the map. Since it does, then we just want to return the vector with elements `[1,2]` which we can get by the value of the map and the current index

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

# Code

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      const int n = nums.size();
      unordered_map<int,int> num_to_index;
      
      int i, complement;
      for (i = 0; i < n; i++) {
        complement = target - nums[i];
        if (num_to_index.count(complement) == 1)
            break;
        
        num_to_index.insert({nums[i], i});
      }
      
      return vector<int> ({num_to_index[complement], i});
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**