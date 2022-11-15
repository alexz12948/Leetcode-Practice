/* Time: O(logN^2) 
 *   * logN for checking if 2 arrays are equal
 *   * logN for creating the number of digits
 * Space: O(logN) 
 *   * logN for array of digits */
class Solution {
public:
  bool reorderedPowerOf2(int n) {
    vector<int> nDigits = countDigits(n);
    for (int i = 0; i < 31; i++) {
      if (arraysEqual(nDigits, countDigits(1 << i)))
        return true;
    }
    
    return false;
  }
  
  // Returns true if both arrays are exactly equal
  bool arraysEqual(vector<int> A, vector<int> B) {
    if (A.size() != B.size())
      return false;

    for (int i = 0; i < A.size(); i++) {
      if (A[i] != B[i])
        return false;
    }

    return true;
  }

  // Creates an array of digits from an integer
  vector<int> countDigits(int num) {
    vector<int> digits(10);
    while (num > 0) {
      digits[num % 10]++;
      num /= 10;
    }

    return digits;
  }
};