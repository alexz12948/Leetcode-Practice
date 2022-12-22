C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

* Run post order DFS to calculate and store the number of nodes in each subtree and the sum of distances for just the root
* Run pre order DFS to calculate the distances for all the nodes in the tree

## Code

```c++
class Solution {
private:
    vector<vector<int>> adj_list;
    vector<int> ans, count;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj_list.resize(n);
        ans.assign(n, 0);
        count.assign(n, 1);
        for (int i = 0; i < edges.size(); i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }

        post_order_dfs(0, -1);
        pre_order_dfs(0, -1);
        return ans;
    }

private:
    void post_order_dfs(int root, int prev) {
        for (int node : adj_list[root]) {
            if (node == prev) continue;
            post_order_dfs(node, root);
            count[root] += count[node];
            ans[root] += ans[node] + count[node];
        }
    }

    void pre_order_dfs(int root, int prev) {
        for (int node : adj_list[root]) {
            if (node == prev) continue;
            ans[node] = ans[root] - count[node] + (count.size() - count[node]);
            pre_order_dfs(node, root);
        }
    }
};
```

## Complexity

**Time Complexity:** $$O(N + E) = O(N + (N - 1)) = O(N)$$ where N is the number of nodes and $$E = N - 1$$ from the problem
**Space Complexity:** $$O(N + E) = O(N + (N - 1)) = O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We know that we can calculate the sum of distances from the root node in $$O(N)$$ time by running some kind of graph traversal algorithm that counts the distance a particular node is from the root and adds them all up. The issue is that when we want to determine this for every node, the runtime becomes $$O(N^2)$$. However, we can pre-compute some information to lower the runtime to be $$O(N)$$. Lets see how this works:

Let's say we know the sum of all distances to the root node, `root_sum`, which can determined in $$O(N)$$ time. As we move to one of it's children, we know that the nodes in the child's subtree become closer and all other nodes move 1 node further away. 

Therefore, if we take the difference between `root_sum` and the number of nodes in the child's subtree, we can find the number of nodes whose distances decrease by 1. Also, we can find the node of nodes whose distances increase by 1 by finding the difference between the total number of nodes and the number of nodes in the child's subtree. With math, we can say

$$childDistance = parentDistance - childSubtreeSize + (n - childSubtreeSize)$$

and simplified:

$$childDistance = parentDistance - 2 * childSubtreeSize + n$$

Another way of describing this is that we are continuously re-rooting the tree and using information about the parent and children to calculate the sum of all the distances

If this was still confusing, I found a video with a great explanation of the solution with a diagram. Here is a [link](https://youtu.be/T81Bpx2OmS4?t=33)

## Approach 

We initialize an adjacency list and create bi-direcitonal connections for every edge pair.

**Note for both DFS functions:** `prev` indicates the identifier for the previous node and at first, it is `-1` since there isn't one for the root

Then, we run a post order DFS to be able to calculate the number of nodes there are in every subtree and store it as `count[i]`. Additionally, we calculate the sum of the distances from all nodes to the root and it gets stored in `ans[0]`

After that, we have all of the information we need to perform re-rooting of the tree and calculatee the sum of distances to all the other nodes.

## Example

Let's work through Example 1, where `n = 6` and `edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]`

![Example 1 Image](https://assets.leetcode.com/uploads/2021/07/23/lc-sumdist1.jpg)

First, we have the post order dfs, which calculates the number of nodes in every subtree and the sum of all node's distances to the root. Here is what all the values would be:

| Index | 0 | 1 | 2 | 3 | 4 | 5 |
|-------|---|---|---|---|---|---|
| count | 6 | 1 | 4 | 1 | 1 | 1 |
| ans   | 8 | 0 | 3 | 0 | 0 | 0 |

Notice that `count[i]` indicates the number of nodes in a subtree with the root at node `i` and `ans[0]` holds the sum of all distances to the root

Next, we run the pre order dfs, which calculates the sum of the distances of all the nodes for a particular node `i`

1. Node 1
We know that `ans[root] = ans[0] = 8` and the number of children in the subtree is 1 (just itself), so `ans[1] = ans[0] - count[1] + n - count[1] = 8 - 1 + 6 - 1 = 12`

2. Node 2
We know that `ans[root] = ans[0] = 8` and the number of children in the subtree is 4, so `ans[2] = ans[0] - count[2] + n - count[2] = 8 - 4 + 6 - 4 = 6`

3. Node 3/4/5
We know that `ans[root] = ans[2] = 6` and the number of children in the subtree is 1 (just itself), so for any node x where is node 3, 4, or 5, `ans[x] = ans[2] - count[x] + n - count[x] = 6 - 1 + 6 - 1 = 10`

We end with a final array of:

| Index | 0 | 1  | 2 | 3  | 4  | 5  |
|-------|---|----|---|----|----|----|
| ans   | 8 | 12 | 6 | 10 | 10 | 10 |

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**