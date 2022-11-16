/* 
Explanation of Solution
-----------------------

Reverse half of the number and if it is equal to the other half 
or the other half / 10 (to account for when there is an
odd number of digits), then it is a palindrome

Complexity
----------
Time: O(log_10(x))
Space: O(1)
*/
class Solution {
public:
  bool isPalindrome(int x) {
    // If it is negative or x ends with a zero and is not zero
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int reversedNumber = 0;
    while (x > reversedNumber) {
      reversedNumber = reversedNumber * 10 + x % 10;
      x /= 10;
    }

    // Second statement is for if x has an odd number of digits
    // Dividing `reversedNumber` by 10 essentially removes that digit
    return x == reversedNumber || x == reversedNumber / 10;
  }
};