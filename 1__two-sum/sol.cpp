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