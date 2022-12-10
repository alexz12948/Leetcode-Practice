class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();

        int ans = 0, curr_min = INT_MAX;
        for (int i = 0; i < n; i++) {
            curr_min = min(curr_min, prices[i]);
            ans = max(ans, prices[i] - curr_min);
        }

        return ans;
    }
};