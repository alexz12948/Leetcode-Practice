class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> vis(n, false);
        
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int curr = q.front();
            if (curr == destination)
                return true;

            if (!vis[curr]) {
                vis[curr] = true;
                for (int i = 0; i < adj[curr].size(); i++)
                    q.push(adj[curr][i]);
            }

            q.pop();
        }

        return false;
    }
};