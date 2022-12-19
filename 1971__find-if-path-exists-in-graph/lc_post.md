C++ || BFS || Easy to Understand with In-Depth Explanation and Examples || O(V + E)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Create an adjacency list and run BFS from `source` and see if you can find `destination`

# Approach

First, we initialize the adjacency list by creating an array of length `n` that holds arrays. We also have to initialize a visited array to prevent us from visiting a node that we already considered

Then, since we have a bidirectional graph, for every edge `edge = [u,v]`, we push `v` onto `u`'s list and `u` onto `v`'s list

Then, we initialize a queue, push `source` onto the queue, and run BFS from `source`. If we found `destination`, we return `true`.

Otherwise, if it hasn't been visited yet, then we set that node to be visited and push all of its neighbors onto the queue. At the end regardless of whether or not it has been visited, we pop the front value from the queue

# Example

I think the [example in the leetcode solution](https://leetcode.com/problems/find-if-path-exists-in-graph/solutions/2715942/find-if-path-exists-in-graph/?orderBy=most_votes) does a very good job of illistrating this, so I will leave that to them since my art skills are not comparable!

# Complexity

**Time Complexity:** $$O(V + E)$$ where V is the number of nodes `n` and E is the number of edges
**Space Complexity:** $$O(V + E)$$

# Code

```c++
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
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**