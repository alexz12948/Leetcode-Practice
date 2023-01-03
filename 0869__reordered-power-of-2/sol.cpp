/* 
Explanation of Solution
-----------------------

The basic idea is that we only have to check from 2^0 up to 2^31 since
we know the upper bound of n. Also, we know that two numbers are the same
(or can be after reordering) if they contain the same frequency of digits.

Therefore, the algorithm is to generate 31 different powers of 2 and
compare their digits to see whether or not they are the same

Complexity
----------
Time: O(logN^2) --> logN for checking if 2 arrays are equal and 
                    logN for creating the number of digits
Space: O(logN) --> logN for array of digits
*/
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