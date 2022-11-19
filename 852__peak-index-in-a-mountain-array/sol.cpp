/*
Explanation of Solution
-----------------------

This is an interesting question that uses binary search

The basic idea is that we want to continue this process until
the pointers cross. There is no need to check whether or not
there is a peak because when the loop exits, there must be a
peak at the left pointer. 

Complexity
----------
Time: O(logn)
Space: O(1) 
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = size(arr) - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};
