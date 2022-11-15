// Note to self: did this question to see how permutations work in C++

/* Time: O(logN! * logN)
 *   * logN! for permutations of digits of N
 *   * logN for computing if a number is a power of 2
 * Space: O(logN) 
 *   * logN for array of digits */
class Solution {
public:
  // Returns true if nDigits represents a power of 2
  bool isPowerOf2(int n) {
    while (n > 0 && ((n & 1) == 0))
      n >>= 1;

    return n == 1;
  }

  // Creates an integer representation of an array of digits
  int numberize(vector<int> digits) {
    int n = 0;
    for (int digit : digits)
      n = n * 10 + digit;
    
    return n;
  }

  bool reorderedPowerOf2(int n) {
    vector<int> nDigits;
    while (n > 0) {
      nDigits.push_back(n % 10);
      n /= 10;
    }

    // This is necessary for next_permutation
    sort(nDigits.begin(), nDigits.end());

    do {
      if (nDigits[0] == 0)
        continue;

      if (isPowerOf2(numberize(nDigits)))
        return true;
    } while (next_permutation(nDigits.begin(), nDigits.end()));
    
    return false;
  }
};