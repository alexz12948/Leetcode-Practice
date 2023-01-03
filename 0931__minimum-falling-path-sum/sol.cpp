class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];

        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = matrix[i][j] + getMinOfAbove(dp, i, j);

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
private:
    int getMinOfAbove(vector<vector<int>>& m, int row, int col) {
        if (col == 0)
            return min(m[row - 1][col], m[row - 1][col + 1]);
        else if (col == m.size() - 1)
            return min(m[row - 1][col], m[row - 1][col - 1]);

        return min({m[row - 1][col - 1], m[row - 1][col], m[row - 1][col + 1]});
    }
};