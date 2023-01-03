/*
Explanation of Solution
-----------------------

Difficult question... to come back to

In essence it is a variation on merge sort, but honestly no idea

https://leetcode.com/problems/count-of-range-sum/discuss/2176526/Merge-Sort-BIT-Segment-Tree-oror-C%2B%2B

Complexity
----------
Time: O(nlogn)
Space: O(n) 
*/


class Solution {
    typedef long long ll;
    bool inRange(ll val, int lower, int upper) {
        return val >= lower && val <= upper;
    }

    void mergeArrays(vector<ll>& sums, int left, int mid, int right) {
        vector<ll> tmp(right - left + 1);
        int p = 0, l = left, r = mid + 1;
        while (l <= mid && r <= right) 
            tmp[p++] = sums[l] <= sums[r] ? sums[l++] : sums[r++];
        while (l <= mid) tmp[p++] = sums[l++];
        while (r <= right) tmp[p++] = sums[r++];

        l = left, p = 0;
        while (l <= right)
            sums[l++] = tmp[p++];
    }

    int countRangeSumSubarray(vector<ll>& sums, int left, int right, int lower, int upper) {
        if (left == right) return inRange(sums[left], lower, upper) ? 1 : 0;

        int mid = (left + right) / 2;
        int cnt = countRangeSumSubarray(sums, left, mid, lower, upper) +
                  countRangeSumSubarray(sums, mid + 1, right, lower, upper);

        // 
        int i = left, k = mid + 1, j = mid + 1;
        while (i <= mid) {
            ll lower_bound = sums[i] + lower, upper_bound = sums[i] + upper;
            while (j <= right && sums[j] <= upper_bound) j++;
            while (k <= right && sums[k] < lower_bound) k++;
            cnt += j - k;
            i++;
        }
        mergeArrays(sums, left, mid, right);
        return cnt;
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        const int n = size(nums);
        vector<ll> sums(n, 0);
        sums[0] = nums[0];
        for (int i = 1; i < n; i++) sums[i] = sums[i - 1] + nums[i]; 

        return countRangeSumSubarray(sums, 0, n - 1, lower, upper);
    }
};
