/*
Explanation of Solution
-----------------------

This is an interesting question that uses binary search

The basic idea is that we want to continue this process until
the pointers cross. For me, it is intuitive to check whether or not
the point is found, but it can be done without it

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
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
                return mid;
            
            if (arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};
