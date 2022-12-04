Title: C++ || Easy to Understand with In-Depth Explanation || O(n)
Tags: cpp, c++, easy-understanding, clean code, beginner, beginner friendly, easy, prefix sum

### PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

### Intuition

By using the brute force approach, you must consistently calculate the sum of elements index 0 --> i and index i+1 -> n - 1. However, by precomputing the prefix sums of every element in O(n), we can calculate the average difference in O(1) time

### Approach

First, we need to generate the prefix sums array, which means at index i it holds the sum of every element from 0 to i.

After this array is generated we want to follow exactly what the problem defintion says: the average difference is absolute difference between the average of the first i + 1 elements and last n - i - 1 elements. 

To find the average of the first i + 1 elements, we just have to do prefix_sum[i] / (i + 1) by definition

To find the average of the last n - i - 1 elements, we need to take the difference between the sum of the total array and the partial sums up to that point. This is because if you subtract off the first i + 1 elements from the total sum (which is found in the last position), then you must be left with the sum of elements from i + 2 to the end (n - i - 1 elements). There is one caveat which is that when i == n - 1 (the last element) it may cause a divide by 0 error. Therefore, I just added in a check right before if n - i - 1 == 0, then make the last elements sum 0 as well.

### Complexity

**Time Complexity:** O(n)
**Space Complexity:** O(n)

### Code

```c++
typedef long long ll;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        const int n = nums.size();

        vector<ll> partial_sums(n, nums[0]);
        for (int i = 1; i < n; i++)
            partial_sums[i] = partial_sums[i - 1] + nums[i];

        int minAvgDiff = INT_MAX, ans = 0;
        ll first_elements, last_elements, currDiff;
        for (int i = 0; i < n; i++) {
            first_elements = partial_sums[i] / (i + 1);
            last_elements = n - i - 1 != 0 ? (partial_sums.back() - partial_sums[i]) / (n - i - 1) : 0;
            currDiff = abs(first_elements - last_elements);
            if (currDiff < minAvgDiff) {
                minAvgDiff = currDiff;
                ans = i;
            }
        }

        return ans;
    }
};
```

### Optimized Code with Space O(1)

```c++
typedef long long ll;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        const int n = nums.size();

        ll total_sum = 0;
        for (int i = 0; i < n; i++)
            total_sum += nums[i];

        int minAvgDiff = INT_MAX, ans = 0, currAvgDiff;
        ll first_elements, last_elements, currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            first_elements = currSum / (i + 1);
            last_elements = n - i - 1 != 0 ? (total_sum - currSum) / (n - i - 1) : 0;
            currAvgDiff = abs(first_elements - last_elements);
            if (currAvgDiff < minAvgDiff) {
                minAvgDiff = currAvgDiff;
                ans = i;
            }
        }

        return ans;
    }
};
```