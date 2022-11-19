/*
Explanation of Solution
-----------------------

This is my convoluted solution that I came up with, but
it was a struggle... take a look at the other one for
a more in depth look at that approach and why it is
probably preferred

Complexity
----------
Time: O(n)
Space: O(1) 
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int n = size(nums);
        int right = 0, ans = 0;
        for (int left = 0; left < n; left++) {
            while (right < n) {
                if (nums[right++] == 0) k--;
                
                if (k < 0) break;
                else ans = max(ans, right - left);
            }
            if (right == n) break;
            if (nums[left] == 0) k++;    
        }

        return ans;
    }
};
