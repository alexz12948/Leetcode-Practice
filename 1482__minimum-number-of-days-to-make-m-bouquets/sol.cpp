/*
Explanation of Solution
-----------------------

The idea is that we know that the answer lies between day 1 and the
maximum day that exists in `bloomDay` since we know that the day
will either lie in this range (unless we don't have enough flowers)
for it.

Then we can binary search of the days and figure out the number of
bouquets that can be created by a particular day. If we can create
>= m bouquets, then we know we can try to go lower so we shrink the
upper bound. If we can't create it, then we know we must go higher
and the day cannot be included so we go +1. At the end, the upper
bound will contain the minimum number of days

For the numberOfBouquets function, we just keep track of the number
of flowers that are next to each other. Then, when there are is a
flower that hasn't bloomed, then we determine the number of bouquets
that can be created with the flowers we have found (cnt / k) and
add that to the answer. 

Complexity
----------
Time: O(nlogmaxDay) where maxDay is the largest day in `bloomDay`
Space: O(1) 
*/
class Solution {
public:
    static int numberOfBouquets(vector<int>& bloomDay, int k, int days) {
        const int n = size(bloomDay);
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= days) cnt++;
            else {
                ans += (cnt / k);
                cnt = 0;
            }
        }

        return ans + (cnt / k);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * size(bloomDay) < 1LL * m * k) return -1;

        int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end()), mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (numberOfBouquets(bloomDay, k, mid) >= m)
                right = mid;
            else
                left = mid + 1;
        }

        return right;
    }
};
