/*
Explanation of Solution
-----------------------

Iterate for n - k times and create substrings of length k. If the substring
is not zero and is a divisor of `num`, then add one to the solution

Complexity
----------
Time: O(logn) 
Space: O(logn) 
*/
class Solution {
public:
  int divisorSubstrings(int num, int k) {
    int ans = 0, currInt;

    string s = to_string(num);
    for (int i = 0; i <= s.size() - k; i++) {
      currInt = stoi(s.substr(i, k));
      if (currInt != 0 && num % currInt == 0)
        ans++;
    }

    return ans;     
  }
};