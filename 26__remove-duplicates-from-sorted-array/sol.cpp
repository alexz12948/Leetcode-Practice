/* Time: O(n)
 * Space: O(1) */
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    const int n = nums.size();
    int num_unique = 0;

    for (int i = 1; i < n; i++) {
      if (nums[i] != nums[num_unique]) {
        nums[++num_unique] = nums[i];
      }
    }

    return num_unique + 1;
  }
};