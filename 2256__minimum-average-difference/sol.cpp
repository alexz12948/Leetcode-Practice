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
