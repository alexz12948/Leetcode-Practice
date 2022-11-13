const int nMax = 10e7;
bool arr[nMax];

/* Time: O(nlogn)
 * Space: O(n) */
class Solution {
public:
  int countPrimes(int n) {
    if (n == 0 || n == 1) return 0;

    for (int i = 2; i < n; i++) arr[i] = true;

    int ans = 0;
    for (int i = 2; i <= n / 2; i++) {
      if (arr[i]) {
        ans++;
        for (int j = i * 2; j <= n; j += i) {
          arr[j] = false;
        }
      }
    }

    for (int i = n / 2 + 1; i < n; i++) {
      ans += (int)arr[i];
    }

    return ans;
  }
};