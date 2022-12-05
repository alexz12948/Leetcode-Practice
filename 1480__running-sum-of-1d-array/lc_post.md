Title: C++ || Easy to Understand with In-Depth Explanation || O(N)
Tags: cpp, c++, easy-understanding, clean code, beginner, beginner friendly, easy

### PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

### Intuition

Use the original array to hold the running sum

### Approach

The first index will just be itself, then from index 1 to n, it will be `nums[i] += nums[i - 1]` since you just want to add the previous value onto the current value continuously till the end. Then you just return the original array that was passed in.

### Complexity

**Time Complexity:** O(n)
**Space Complexity:** O(1)

### Code

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