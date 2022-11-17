/*
Explanation of Solution
-----------------------

I was SEVERELY mislead because I thought this could be done using
the sliding window technique. However I was mistaken because of the
fact that there is no way to easily determine whether or not the endIndex
is the final endIndex

The idea behind my solution is by using either a hashmap or a vector of length
2n + 1, you could track the value of the count and look to see if the count 
has been that value before. Then you just take the difference between the indices
where the counts were equal since you know that there had to be equal amounts of
1s and 0s and take the maximum of all of them to find the solution

Complexity
----------
Time: O(n)
Space: O(n) 
*/

class Solution {
public:
  int findMaxLength(vector<int>& nums) {  
    const int n = nums.size();

    if (n == 1)
      return 0;

    int cnt = 0, ans = 0;
    unordered_map<int,int> idxMap; // (count, index)

    // This is to help with math for when the entire array is valid
    idxMap.insert({0, -1});
    for (int i = 0; i < n; i++) {
      cnt += nums[i] == 1 ? 1 : -1;

      if (idxMap.count(cnt) == 1) {
        ans = max(ans, i - idxMap.at(cnt));
      } else {
        idxMap.insert({cnt, i});
      }
    }

    return ans;
  }
};