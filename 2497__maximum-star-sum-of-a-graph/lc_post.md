C++ || Easy to Understand with In-Depth Explanation and Examples || O(mlogm)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

1. Create a list of the values that a particular node can reach. 

This is similar to an adjacency list, but opposed to the actual edges, we just put the adjacent node's values in a priority queue so that it is in increasing order

2. Loop through each queue at most k times (depending on the number of edges) and we get the current sum of every node 
3. Update the answer if the current sum is greater than the best answer so far

# Approach

First, we need to create the list of priority queues. We can do that by initializing a list of priority queues, then for every edge (which is a node pair) $$[a_i, b_i]$$, we push $$b_i$$ node value onto $$a_i$$'s queue and same thing vice versa

Then, for every node, we grab its priority queue and then calculate the current sum of the best k edges. We update the answer every iteration since the node's values could be negative, so it is just easiest to update it every time

# Complexity

* $$n$$ is the number of nodes in the graph
* $$m$$ is the number of edges in the graph

**Time Complexity:** $$O(mlogm)$$ for initializing the adjacency list
**Space Complexity:** $$O(nm)$$ for the adjacency list

# Code

```c++
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        const int n = vals.size();
        const int m = edges.size();

        vector<priority_queue<int>> adj_list (n);
        for (int i = 0; i < m; i++) {
            adj_list[edges[i][0]].push(vals[edges[i][1]]);
            adj_list[edges[i][1]].push(vals[edges[i][0]]);
        }

        int ans = INT_MIN;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq = adj_list[i];
            int currSum = vals[i];
            for (int j = 0; j < k; j++) {
                ans = max(ans, currSum);
                if (pq.empty()) break;
                currSum += pq.top();
                pq.pop();
            }

            ans = max(ans, currSum);
        }

        return ans;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL OR ASK QUESTIONS BELOW!! 🥺😁**