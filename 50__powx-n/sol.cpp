/* 
Explanation of Solution
-----------------------

This solution uses the idea of fast modular exponentition

a^n has 2 cases: if n is even or if n is odd
* If even, a^n can be written as (a^(n/2))^2
* If odd, a^n can be written as a*a^(n-1)

Using this idea, you can compute an exponentiation in logN time

Complexity
----------
Time: O(log(n))
Space: O(1)
*/
class Solution {
public:
  double myPow(double x, int n) {
    double ans = 1;
    bool is_neg = n < 0;
    x = is_neg ? 1 / x : x;
    long int power = is_neg ? n * -1LL : n;
    while (power) {
      if (power % 2 == 0) {
        x = (1LL * x * x);
        power /= 2;
      } else {
        ans = (1LL * ans * x);
        power--;
      }
    }

    return ans;
  }
};