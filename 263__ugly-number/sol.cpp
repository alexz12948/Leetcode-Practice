/* 
Explanation of Solution
-----------------------

Straightforward solution of continuously dividing the number by the
factor and if the number is 1 at the end, then 2, 3 and 5 are the only prime
factors for `n`

Complexity
----------
Time: O(logn)
Space: O(1)
*/
class Solution {
public:
  bool isUgly(int n) {
    if (n <= 0) return false;

    for (int factor : {2, 3, 5}) {
      while (n % factor == 0) {
        n /= factor;
      }
    }

    return n == 1;
  }
};