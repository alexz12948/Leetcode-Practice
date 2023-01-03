C++ || Easy to Understand with In-Depth Explanation and Examples || O(nm)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Run DFS from every land pixel and keep track of all the pixels that you have visited. If you haven't visited a piece of land, then you run DFS from that land and then increament the number of islands by 1.

The reason why is because when you run DFS from a piece of land, it will discover the entire island. Since you are setting each land coordinate to be visited, then you know that you have discovered the entire island that started at the original coordinate. Therefore, when you find another unvisited piece of land, you know that it is a new island and that you can visit it.

# Approach

Loop through the entire grid and if you find a land piece that hasn't been visited, then run DFS from that particular index and increament the number of islands by 1.

For DFS, create a stack that holds coordinates and push the origin onto the stack. Then, we want to grab the top value of the stack and ensure that it is in the bounds of the grid, it hasn't been visited, and it is not water. If any of those are true, then we just want to move to the next index. Otherwise, we set that coordinate to true and push all of that coordinates neighbors onto the stack.

# Complexity

**Time Complexity:** $$O(nm)$$
**Space Complexity:** $$O(nm)$$ for the visited array, but it could be done in $$O(1)$$ if you use another character to denote a visited piece of land

# Code

```c++
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
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**