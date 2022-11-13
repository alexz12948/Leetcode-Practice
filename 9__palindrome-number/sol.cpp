/* Time: O(log_10(x))
 * Space: O(log_10(x)) */
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