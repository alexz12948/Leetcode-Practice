#define LAND '1'
#define WATER '0'

pair<int,int> dirs[] = {make_pair(1, 0), make_pair(-1, 0),
                        make_pair(0, 1), make_pair(0, -1)};

class Solution {
public:
    int m, n;
    vector<vector<bool>> vis;

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();

        int ans = 0;
        vis = vector<vector<bool>>(m, vector<bool> (n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == LAND && !vis[i][j]) {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        stack<pair<int,int>> st;
        st.push(make_pair(r, c));
        while (!st.empty()) {
            pair<int,int> coord = st.top();
            st.pop();
            if (!inBounds(coord.first, coord.second, m, n) ||
                vis[coord.first][coord.second] ||
                grid[coord.first][coord.second] == WATER)
                continue;

            vis[coord.first][coord.second] = true;

            for (pair<int,int> dir : dirs)
                st.push(make_pair(coord.first + dir.first, coord.second + dir.second));
        }
    }

    bool inBounds(int r, int c, int m, int n) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
};