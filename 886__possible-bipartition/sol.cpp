#define UNCOLORED -1
#define RED 0
#define BLUE 1

// Gives the opposite color of `c`
#define OPPOSITE(c) ((c) == RED ? BLUE : RED);

class Solution {
private:
    vector<vector<int>> adj_list;
    vector<int> colors;

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        adj_list.resize(n + 1);
        colors.resize(n + 1, UNCOLORED);

        for (vector<int> pair : dislikes) {
            int u = pair[0], v = pair[1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        for (int node = 1; node <= n; node++) {
            if (colors[node] == UNCOLORED) {
                if (!is_two_colorable(node)) return false;
            }
        }

        return true;
    }

private:
    // Uses BFS
    bool is_two_colorable(int src) {
        queue<int> q;
        q.push(src);
        colors[src] = RED;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int neighbor : adj_list[curr]) {
                if (colors[neighbor] == colors[curr])
                    return false;

                if (colors[neighbor] == UNCOLORED) {
                    colors[neighbor] = OPPOSITE(colors[curr]);
                    q.push(neighbor);
                }
            }
        }

        return true;
    }
};