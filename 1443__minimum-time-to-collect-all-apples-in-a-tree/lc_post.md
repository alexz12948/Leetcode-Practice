C++ || O(N) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Run DFS from the root and calculate the amount of steps from the bottom up the tree

## Code

```c++
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
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

I am going to use the photo from the [Leetcode Official Solution]() so if you want to take a look at that solution feel free!

![bottom top photo](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/solutions/2864715/Figures/1443/1443-3.png)

As you can see, when there is an apple we need to visit that node which takes 2 trips (one to go to that node and then one for the way back). Additionally, we need to bubble up the trip cost since if there is an apple at the bottom, it costs time to head down a branch to get to the apple. Therefore, if we find an apple, we take the amount of time that we would spend in the subtree plus 2 for the trip to that node.

For example, if we look at the furthest left route, there is an apple. Since there is no nodes in the subtree, we just return `2` since that is the cost to visit that node.

Another example is when we go down the further right route. There is no apple at the bottom and there are no nodes in the subtree, so we wouldn't go all the way down the branch so we would return `0` since we do not want to visit this branch all the way down

## Approach 

* Create an adjacency list
* Run recursive DFS from the root node and keep track of the current node, the parent node, and the `hasApple` array
* Loop through all of the neighbors of the current node
  * If we have already seen the node (`neighbor == parent`), then move onto the next iteration
  * Calculate the time for traversing the neighbor's subtree
  * If there is nonzero time for traversing the neighbor's subtree **OR** the neighbor has an apple, then we take the time taken for traversing the child's tree and then add 2 to a total
* At the end, just return the total for that node to the next node up in the tree

We should have the complete total at the end of this function

## Example

Let's use the first example, where `n = 7`, `edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]`, and `hasApple = [false,false,true,false,true,true,false]`. Here is the image:

![first example image](https://assets.leetcode.com/uploads/2020/04/23/min_time_collect_apple_1.png)

First, we create the bidirectional adjacency list, which will look like this:

```json
{
  0: [1,2],
  1: [4,5],
  2: [3,6],
  3: [],
  4: [],
  5: [],
  6: []
}
```

1. node = 0, parent = -1

We iterate through all of the neighbors. The first neighbor is `1` and it is not equal to parent (`-1`), so we call `dfs(1, 0)`

  a. node = 1, parent = 0

  We iterate through all of the neighbors. The first neighbor is `4` and it is not equal to parent (`0`), so we call `dfs(4, 1)`

    i. node = 4, parent = 1

    We iterate through all of the neighbors and there is none so we return `0`

  b. node = 1, parent = 0

  `childTime = 0` since `4` has 0 time traversing it's subtree (since there is no subtree). However, since `hasApple[4] = true`, we do `totalTime += childTime + 2` --> `totalTime = totalTime + childTime + 2 = 0 + 0 + 2 = 2`

  The next neighbor is `5` and it is not equal to parent (`0`), so we call `dfs(5, 1)`

    i. node = 5, parent = 1

    We iterate through all of the neighbors and there is none so we return `0`

  c. node = 1, parent = 0

  `childTime = 0` since `5` has 0 time traversing it's subtree (since there is no subtree). However, since `hasApple[5] = true`, we do `totalTime += childTime + 2` --> `totalTime = totalTime + childTime + 2 = 2 + 0 + 2 = 4`

  There are no other neighbors, so we return `totalTime = 4`

2. node = 0, parent = -1

`childTime = 4` and since it is nonzero, we do `totalTime += childTime + 2` --> `totalTime = totalTime + childTime + 2 = 0 + 4 + 2 = 6`

The next neighbor is `2` and it is not equal to parent (`-1`), so we call `dfs(2, 0)`

  a. node = 2, parent = 0

  We iterate through all of the neighbors. The first neighbor is `3` and it is not equal to parent (`0`), so we call `dfs(3, 2)`

    i. node = 3, parent = 2

    We iterate through all of the neighbors and there is none so we return `0`

  b. node = 2, parent = 0

  `childTime = 0` and `hasApple[3] = false`, so we don't add anything to the running total.

  The next neighbor is `6` and it is not equal to parent (`0`), so we call `dfs(6, 2)`

    i. node = 6, parent = 2

    We iterate through all of the neighbors and there are none so we return `0`

  c. node = 2, parent = 0

  `childTime = 0` and `hasApple[6] = false`, so we don't add anything to the running total.

  There are no other neighbors, so we return `totalTime = 0`

3. node = 0, parent = -1

`childTime = 0` since `2` has 0 time traversing it's subtree (nobody in the subtree has an apple). However, since `hasApple[2] = true`, we do `totalTime += childTime + 2` --> `totalTime = totalTime + childTime + 2 = 6 + 0 + 2 = 8`

There are no other neighbors, so we return `totalTime = 8`

4. Aftermath

We just return `8`, which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**