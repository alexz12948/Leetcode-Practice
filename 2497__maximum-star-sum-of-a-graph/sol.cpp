class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        const int n = vals.size();
        const int m = edges.size();

        vector<priority_queue<int>> adj_list (n);
        for (int i = 0; i < m; i++) {
            adj_list[edges[i][0]].push(vals[edges[i][1]]);
            adj_list[edges[i][1]].push(vals[edges[i][0]]);
        }

        int ans = INT_MIN;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq = adj_list[i];
            int currSum = vals[i];
            for (int j = 0; j < k; j++) {
                ans = max(ans, currSum);
                if (pq.empty()) break;
                currSum += pq.top();
                pq.pop();
            }

            ans = max(ans, currSum);
        }

        return ans;
    }
};