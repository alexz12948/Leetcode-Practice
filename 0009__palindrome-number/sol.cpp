/* 
Explanation of Solution
-----------------------

Convert the palindrome to a string andd while the front ptr is before
the back ptr, check all the elements using interators

Complexity
----------
Time: O(log_10(x))
Space: O(log_10(x))
*/
class Solution {
public:
  bool isPalindrome(int x) {
    string s = to_string(x);
    auto front = s.begin(), back = s.end() - 1;
    while (front < back) {
      if (*(front++) != *(back--)) return false;
    }

    return true;
  }
};