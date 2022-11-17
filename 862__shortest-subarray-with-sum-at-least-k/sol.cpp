/*
Explanation of Solution
-----------------------

This question was incredibly difficult and I had to utilize a couple
of different sources to come to my answer

The idea behind this question is that you want to keep track of the sums
while making sure that the prefix sums are always increasing. The way you
make this work is with the deque, which is used mainly as a queue. The elems
in the queue are 2 int which represent the partial sum and the index of that sum

If you get a sum that decreases the total amount, then it isn't necessary to
consider any candidates that have a greater sum than it anymore since the
partial sum array is no longer increasing from index - 1 to index. This is taken
care of with while loop 2. While the current sum is less than the last value in
the queue, you just remove that value since it doesn't add anything to your solution

Then, when there are values in the queue, you need to think about whether queue
has a potential subarray. You do this by taking the difference between the
current sum and the first subarray sum in the queue. If the difference
between those values is >= k, then you know that the subarray from the current
index to the index where the first subarray was found is a possible solution.
Update the answer with the minimum of itself and the possible solution. Repeat
this process until all the elements have been processed

Complexity
----------
Time: O(N)
Space: O(N) 
*/

class Solution {
public:
  int shortestSubarray(vector<int>& nums, int k) {
    const int n = nums.size();
    long sum = 0, ans = INT_MAX;
    deque<pair<long,long>> inc_q; // Index, sum at index

    for (long i = 0; i < n; i++) {
      sum += nums[i];

      if (sum >= k)
        ans = min(ans, i + 1);

      // Reducing the window from the front
      while (!inc_q.empty() && sum - inc_q.front().second >= k) {
        ans = min(ans, i - inc_q.front().first);
        inc_q.pop_front();
      }

      while (!inc_q.empty() && sum <= inc_q.back().second) {
        inc_q.pop_back();
      }  

      inc_q.push_back({i, sum});
    }

    return ans < INT_MAX ? ans : -1;
  }
};