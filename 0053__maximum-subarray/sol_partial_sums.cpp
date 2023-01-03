/* 
Explanation of Solution
-----------------------

This uses a modified partial sums approach to determine the maximum subarray size

Pretty much, you want to create another array where partial_sums[i] is the sum
of the first i elements. Then, you need to find the largest difference between
the current indice's value and the minimum that you have seen so far while iterating

The original algorithm is O(2n) but I was able to modify it so that it works in 1 loop

Complexity
----------
Time: O(N) where N is the size of the input vector
Space: O(N) where N is the size of the input vector
*/

const int lenMax = 10e5 + 1;
int partial_sums[lenMax];

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    const int n = nums.size();
    
    partial_sums[0] = nums[0];
    int ans = nums[0], currMin = min(0, nums[0]);
    for (int i = 1; i < n; i++) {
      partial_sums[i] = partial_sums[i - 1] + nums[i];

      if (partial_sums[i] - currMin > ans)
        ans = partial_sums[i] - currMin;
      
      if (partial_sums[i] < currMin)
        currMin = partial_sums[i];
    }

    return ans;
  }
};