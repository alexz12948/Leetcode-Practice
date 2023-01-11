class Solution {
public:
    vector<vector<int>> adj;

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        for (vector<int>& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0, -1, hasApple);
    }
private:
    int dfs(int node, int parent, vector<bool>& hasApple) {
        int totalTime = 0, childTime = 0;

        for (int& neighbor : adj[node]) {
            if (neighbor == parent)
                continue;

            childTime = dfs(neighbor, node, hasApple);

            if (childTime || hasApple[neighbor])
                totalTime += childTime + 2;
        }

        return totalTime;
    }
};