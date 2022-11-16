/*
Explanation of Solution
-----------------------

Since the array is in sorted order, we can use that to our advantage. Inside of the
loop, as long as the value is the same, we increament the count of the number of
times a certain value was seen. If we move onto another value, we reset the count

If the count every goes above 25% (or count * 4 > n), then 
we know that must be the number

Complexity
----------
Time: O(n)
Space: O(1)
*/
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