/*
Explanation of Solution
-----------------------

Using a hashtable to keep track of all the values that have been seen,
what we do is iterate through the array and see if a values complement exists.
AKA target - currvalue exists. If so, then we know that currval + complement = target
which is our answer

Complexity
----------
Time: O(N)
Space: O(N) 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      const int n = nums.size();
      
      unordered_map<int,int> visited;
      vector<int> ans;
      
      int complement;
      for (int i = 0; i < n; i++) {
        complement = target - nums[i];
        if (visited.count(complement)) {
          ans = {visited[complement], i};
          break;
        }
          
        
        visited.insert({nums[i], i});
      }
      
      return ans;
    }
};