/*
Explanation of Solution
-----------------------

This solution is actually pretty elegant because it uses the sliding window
technique, but in a very interesting way. The idea is to use 2 different sliding
windows: one to minimize the requirement and one to maximize the requirement.
For example, one of them when it hits the k, then the window shrinks, while
the other one when it exceeds k, then the window shrinks

I originally did it by trying to do 1 sliding window, but I determined that
that wouldn't work because I would always be missing something. I also originally
did it with functions opposed to a class (like the solution did), but I think that
it makes sense to try it yourself and if your solution isn't as nice as the solution,
just do it like the solution so that you can better remember

Complexity
----------
Time: O(N)
Space: O(N) 
*/

class Window {
public:
  int numUnique = 0;

  void add(int x) {
    numUnique += ++window[x] == 1 ? 1 : 0;
  }

  void remove(int x) {
    numUnique -= --window[x] == 0 ? 1 : 0;
  }

private:
  unordered_map<int,int> window;
};

class Solution {
public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
      const int n = nums.size();
      int ans = 0, left1 = 0, left2 = 0, currVal;
      Window window1, window2;

      for (int right = 0; right < n; right++) {
        currVal = nums[right];
        window1.add(currVal);
        window2.add(currVal);

        while (window1.numUnique > k) {
          window1.remove(nums[left1++]);
        }

        while (window2.numUnique >= k) {
          window2.remove(nums[left2++]);
        }

        ans += left2 - left1;
      }

      return ans;
  }
};

