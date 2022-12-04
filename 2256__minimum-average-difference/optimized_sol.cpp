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
