/* 
Explanation of Solution
-----------------------

This uses a greedy approach to determine the maximum subarray size

If the current sum ever goes negative, then we do not want to incorporate
this into the next sum because it can only hurt the next total. Therefore,
the basic idea is that whenever the sum goes negative, reset the sum to
0 and then treat the next element as if it is the start of a new subarr

Complexity
----------
Time: O(N) where N is the size of the input vector
Space: O(1)
*/
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    const int n = nums.size();
    int ans = nums[0], curr_sum = 0;

    for (int i = 0; i < n; i++) {
      curr_sum += nums[i];
      
      ans = max(curr_sum, ans);

      if (curr_sum < 0)
        curr_sum = 0;
    }

    return ans;
  }
};