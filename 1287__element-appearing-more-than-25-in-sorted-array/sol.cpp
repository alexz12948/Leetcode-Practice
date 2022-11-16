/* Time: O(n)
 * Space: O(1) */
class Solution {
public:
  int findSpecialInteger(vector<int>& arr) {
    const int n = arr.size();
    int count = 1;
    
    for (int i = 1; i < n; i++) {
      if (arr[i] != arr[i - 1])
        count = 0;
      
      if (++count * 4 > n)
        return arr[i];
    }

    return arr[0];
  }
};