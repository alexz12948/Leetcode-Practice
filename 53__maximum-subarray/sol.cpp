/* Time: O(N) where N is the size of the input vector
 * Space: O(1) */
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