/*
Explanation of Solution
-----------------------

Loop all values from `left` to `right` and determine whether or not
a number is self dividing. If it is, then add it to the list

Complexity
----------
Time: O((R - L) * logR) --> where R and L are the inputted parameters
Space: O(R - L)
*/

class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ans;
    for (; left <= right; left++) {
      if (left < 9) {
        ans.push_back(left);
        continue;
      }

      if (isSelfDividing(left))
        ans.push_back(left);
    }

    return ans;
  }

  // Returns true if `num` is self dividing
  bool isSelfDividing(int num) {
    int original_value = num;
    int digit;
    while (num) {
      digit = num % 10;
      if (digit == 0 || original_value % digit != 0) 
        return false;
      num /= 10;
    }

    return true;
  }
};
