/* Time: O(log(n))
 * Space: O(1) */
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