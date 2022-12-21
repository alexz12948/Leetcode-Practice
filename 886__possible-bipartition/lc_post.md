C++ || Easy to Understand with In-Depth Explanation and Examples || O(N + E)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Determine whether the graph is 2-colorable using BFS or DFS

## Code

```c++
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
```

## Complexity

**Time Complexity:** $$O(N + E)$$ where N is the number of people and E is the number of dislike pairs
**Space Complexity:** $$O(N + E)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We want to convert this problem to be a graph where the people are nodes and the dislikes are edges. 

Then, we want to determine whether or not we can split a subgraph into 2 groups of nodes such that every node that has a connection are in 2 different groups. 

Therefore, inside of separating the nodes, we can assign each node a color and ensure that every connected node has a different color. This is otherwise known as [2-colorable](https://en.wikipedia.org/wiki/Bipartite_graph) and is one of the characteristics of a bipartite graph. Take a look at the properties section for more information

## Approach 

First, we want to initialize an adjacency list with bi-directional edges and create an array of colors where all of the nodes are (at first) uncolored.

Then we loop through all of the nodes. If any of them are uncolored, then we determine whether the subgraph that contains node `i` is 2-colorable. This uses BFS under the hood and continuously sets the next nodes color to be the opposite of the current nodes color.

While running BFS, if a neighbor is already colored but it is the same color as the current node, then we know that the graph is not 2-colorable and we return false.

If we are able to color the entire graph with 2 colors, then we know that it is a proper bipartite graph

## Example

For this, I have no drawing ability, so I will go through example 3 since it is just a line of nodes from 1 to 5.

We know that node 1 is connected to node 2, node 2 to node 3, etc. so when we begin iterating, we will see that node 1 is not colored, so we can run BFS from there.

As we iterate, here is how the coloring process will go:
1. Node 1 gets assigned color RED
1. Node 1 neighbors that are not colored yet get assigned color BLUE (aka Node 2 and 5)
1. Node 2 neighbors that are not colored yet get assigned color RED (aka node 3)
1. Node 5 neighbors that are not colored yet get assigned color RED (aka node 4)
1. Node 3 neighbors that are not colored yet get assigned color BLUE (aka node 4) however this is a contradiction since node 4 was already colored RED in step 4, therefore the graph is not 2 colorable so we return `false`

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**