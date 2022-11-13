class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ans;
    for (; left <= right; left++) {
      if (left < 9) {
        ans.push_back(left);
        continue;
      }

      int num = left;
      int digit;
      bool is_dividing = true;
      while (num) {
        digit = num % 10;
        if (digit == 0 || left % digit != 0) {
          is_dividing = false;
          break;
        }
        num /= 10;
      }

      if (is_dividing) ans.push_back(left);
    }

    return ans;
  }
};
