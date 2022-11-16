/* 
Explanation of solution
-----------------------

In essense, this uses the partial sums array idea combined with a mathematical formula:
abs(A) + abs(B) = max(A + B, A - B, -A + B, -A - B)

Using this idea, the original formula can be refactored into 4 statements:
1. (arr1[i] + arr2[i] + i) - (arr1[j] + arr2[j] + j)
2. (arr1[i] + arr2[i] - i) - (arr1[j] + arr2[j] - j)
3. (arr1[i] - arr2[i] + i) - (arr1[j] - arr2[j] + j)
4. (arr1[i] - arr2[i] - i) - (arr1[j] - arr2[j] - j)

These are represented using the 4 vectors. Then we must find the the difference
between the maximum and the minimum values between these 4 cases. This
gives us our solution

Complexity
----------
Time: O(n)
Space: O(n)
*/
class Solution {
public:
  int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    const int n = arr1.size();
    vector<int> doublePos(n, 0), doubleNeg(n, 0), posNeg(n, 0), negPos(n, 0);

    for (int i = 0; i < n; i++) {
      doublePos[i] = arr1[i] + arr2[i] + i;
      doubleNeg[i] = arr1[i] - arr2[i] - i;
      posNeg[i] = arr1[i] + arr2[i] - i;
      negPos[i] = arr1[i] - arr2[i] + i;
    }

    return max4(
      diffOfMaxAndMin(doublePos, n), 
      diffOfMaxAndMin(doubleNeg, n), 
      diffOfMaxAndMin(posNeg, n), 
      diffOfMaxAndMin(negPos, n)
    );
  }
  
  // Returns the maximum of 4 integers
  int max4(int n1, int n2, int n3, int n4) {
    return max(max(n1, n2), max(n3, n4));
  }

  // Finding the difference between the maximum and minimum values in `arr`
  int diffOfMaxAndMin(vector<int>& arr, const int n) {
    int max_sum = arr[0], min_sum = arr[0];
    for (int i = 1; i < n; i++) {
      max_sum = max(max_sum, arr[i]);
      min_sum = min(min_sum, arr[i]);
    }

    return max_sum - min_sum;
  }
};