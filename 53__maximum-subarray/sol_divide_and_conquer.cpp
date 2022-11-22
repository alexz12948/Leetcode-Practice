/* 
Explanation of Solution
-----------------------

This is the divide and conquer approach used on this problem.

The basic idea is that we want to continuously divide the arrays until you get to the bottom call. Then, you know that the maximum subarray sum is either: 

1. Entirely in the left half
2. Entirely in the right half
3. Goes over middle point

Therefore, you must find the maximum out of the left half, right half, and a solution
that goes over the middle point. The functions `maxSubArrayLeft/Right` allow
you to calculate the maximum sum that goes over the middle point

Complexity
----------
Time: O(nlogn) 
Space: O(1)
*/
class Solution {
public:
  int maxSubArrayRight(vector<int>& nums, int mid, int right) {
    int ans = nums[mid + 1], sum = 0;
    for (int r = mid + 1; r <= right; r++) {
      sum += nums[r];
      ans = max(ans, sum);
    }

    return ans;
  }

  int maxSubArrayLeft(vector<int>& nums, int left, int mid) {
    int ans = nums[mid], sum = 0;
    for (int l = mid; l >= left; l--) {
      sum += nums[l];
      ans = max(ans, sum);
    }

    return ans;
  }

  int maxSubArrayDivide(vector<int>& nums, int left, int right) {
    if (left == right) return nums[left];

    int mid = (left + right) / 2;
    return max({maxSubArrayDivide(nums, left, mid), 
                maxSubArrayDivide(nums, mid + 1, right), 
                maxSubArrayLeft(nums, left, mid) + maxSubArrayRight(nums, mid, right)
                });
  }

  int maxSubArray(vector<int>& nums) {
    return maxSubArrayDivide(nums, 0, size(nums) - 1);
  }
};