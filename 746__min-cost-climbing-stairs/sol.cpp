class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();

        int two_steps_ago = cost[0], last_step = cost[1], curr;
        for (int i = 2; i < n; i++) {
            curr = cost[i] + min(last_step, two_steps_ago);
            two_steps_ago = last_step;
            last_step = curr;
        }

        return min(last_step, two_steps_ago);
    }
};