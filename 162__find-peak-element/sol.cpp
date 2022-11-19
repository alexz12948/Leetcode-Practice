/*
Explanation of Solution
-----------------------

This solution uses binary search

Since we need to check surrounding elements, we want to avoid
out of bound issues. This then means that we need to check for
some base cases. The basic one is that if there is only 1 elem,
then that must be a peak. Then, we need to check if the first/last
elem is a peak. If both of these don't return, then we want
to run binary search from [1,n-2] since we already checked
0 and n - 1

Another alternative that we could do is set the first and last element
of the array to be INT_MIN and then try to find the solution. This avoids
all issues with boundary and makes the code cleaner. The main issue is that
when inserting at the front of a vector, then it is O(n) which is an invalid
solution

Complexity
----------
Time: O(logn)
Space: O(1) 
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n = size(nums);

        if (n == 1)
            return 0;

        if (nums[0] > nums[1])
            return 0;
        else if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int left = 1, right = size(nums) - 2, mid;
        while (left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                return mid;

            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};
