/* 
Explanation of Solution
-----------------------

Since the array is sorted, then we can use that information when trying to
determine where to place the next unique. We have a pointer that points at the
first unique element. The loop goes through all the elements and if the iterator
does not match the pointer to the unique element, then it must mean that we are
looking at a new element. It then we move the pointer up on spot and place the
new unique element in there

Complexity
----------
Time: O(n)
Space: O(1)
*/
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