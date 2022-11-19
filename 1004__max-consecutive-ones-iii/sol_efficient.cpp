/*
Explanation of Solution
-----------------------

During this problem, I now understand sliding window a lot better
than I did before. I had to look at the discussion to help me
come up with this solution (though I was able to do it on my own)

The basic idea behind this solution is that we want to
continue to iterate the sliding window at first until it has the maximum
size that it can. Then, as soon as it becomes invalid, we want to increament
BOTH the left and right pointer just as before. 

Since we are trying to maximize a value, we don't care about shrinking the
array. In essence, we keep the window the same size and just update
the values that are coming into view and going out of view. 

At the end of the loop, we should have the maximum size since right - left
would have been the max size so far

Complexity
----------
Time: O(n)
Space: O(1) 
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int n = size(nums);
        int left = 0, right = 0;
        for (; right < n; right++) {
            if (nums[right] == 0) k--;
            if (k < 0 && nums[left++] == 0) k++;
        }

        return right - left;
    }
};
