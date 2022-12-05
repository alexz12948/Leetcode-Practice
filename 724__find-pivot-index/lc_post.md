Title: C++ || Easy to Understand with In-Depth Explanation || O(N)
Tags: cpp, c++, easy-understanding, clean code, beginner, beginner friendly, easy, prefix sum

### PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

### Intuition

Go through the algorithm like they described, but pre-compute the total sum of the entire array and use that to your advantage while trying to compute the pivot index. Notice that for any pivot index `i` that you are checking, notice that the left sum is the current running sum to index `i - 1` and the right sum is the `total` sum minus the values from index 0 to i. For example, in example 1 with input `[1,7,3,6,5,6]`, with a pivot index of 3. The left sum is the running sum from 0 to i - 1 (`nums[0] + nums[1] + nums[2]`) and the right sum is equal to (`total - nums[0] - nums[1] - nums[2] - nums[3]` where total is the sum of all indices)

### Approach

Initialize the answer to be `-1` since we do not know whether there is an answer in the array. Then, you find the sum of all the elements in `nums` and keep it in a variable. Then, we initialize the current sum to be 0. Finally, we want to iterate over the original array again, but this time, we subtract the pivot index's value (`total -= nums[i]`) and then check if the left sum equals the right sum. If it does, we found our answer and we exit the iteration. If it doesn't, then we just add the current pivot index's value to the running sum since we are about to iterate over to the next value and we know that index `i` is not the pivot index.

### Complexity

**Time Complexity:** O(n) where n is the length of the array
**Space Complexity:** O(1)

### Code

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