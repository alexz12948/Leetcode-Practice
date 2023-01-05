class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr_col = i;
            for (int j = 0; j < m; j++) {
                int next_col = curr_col + grid[j][curr_col];
                if (next_col < 0 || next_col >= n || grid[j][curr_col] != grid[j][next_col]) {
                    curr_col = -1;
                    break;
                }

                curr_col = next_col;
            }
            ans[i] = curr_col;
        }

        return ans;
    }
};