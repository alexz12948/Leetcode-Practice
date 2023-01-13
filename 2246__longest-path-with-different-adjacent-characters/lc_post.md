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

Using DFS and a greedy approach:
* Run DFS from every child
* Find the longest path and second longest path
* Update the current answer to be the max between `longest + secondLongest + 1` and itself

## Code

```c++
class Solution {
public:
    int currLongestPath = 1;
    vector<vector<int>> children;

    int longestPath(vector<int>& parent, string s) {
        const int n = parent.size();
        children.resize(n);
        for (int i = 1; i < n; i++)
            children[parent[i]].push_back(i);

        dfs(0, s);
        return currLongestPath;
    }
private:
    int dfs(int node, string& s) {
        int longestChain = 0, secondLongestChain = 0;
        for (int child : children[node]) {
            int longestChainFromChild = dfs(child, s);

            if (s[child] == s[node])
                continue;

            if (longestChainFromChild > longestChain) {
                secondLongestChain = longestChain;
                longestChain = longestChainFromChild;
            } else if (longestChainFromChild > secondLongestChain)
                secondLongestChain = longestChainFromChild;
        }

        currLongestPath = max(currLongestPath, longestChain + secondLongestChain + 1);
        return longestChain + 1;
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

The basic idea is that we want to use DFS from every node in the tree and keep track of the longest and second longest path from a particular node. Then, we keep track of the maximum path by taking the sum of the longest and second longest path plus 1 (for the current node that we are working with). 

The only issue is if the current node and the child node has the same character, we don't want to update that node's longest/second longest chain (since we can't use that). HOWEVER, we still want to explore that child for a possible path since even though `node` and `child` have the same characters, the longest path could exist in some path inside of the subtree with `child` as the root

## Approach 

First, we need to convert the parent array to be a children array by giving each node a unique identifier. We do this by taking the looping through the parent array and using the current index as the identifier and appending it onto the parent's array

Then we run dfs from the root node (`0`). We want to initialize 2 variables to hold the longest and second longest chain (`lonestChain` and `secondLongestChain` respectively). We need to loop through all of the children of the current node. For every node, we:

* Run dfs from the child (to explore all possiblities) and keep track of the length of the longest chain from `child`
* If the character of `child` is the same as the current node `node`, we don't want to update our chain variables since we can't go down that path (aka `continue`)
* Then we update the longestChain or secondLongestChain based on the value returned from the recursive dfs

After we looped through all of the children, we should have the longest and second longest chain from this particular node. We then update the current longest path to be the maximum between itself and `longestPath + secondLongestPath + 1` (plus 1 for the current node).

*Note* that I chose to make the current longest path and the children array global variables, but you could also pass this into the function and pass by reference to do the same thing

## Example

Let's use the second example, where `parent = [-1,0,0,0]` and `s = "aabc"`

First, we need to create the children array. This may be a little confusing, so I wrote out an iteration table to help with understanding:

| i | parent[i] | children[parent[i]] |
|:-:|:---------:|:-------------------:|
| 1 |     0     |        `[1]`        |
| 2 |     0     |       `[1,2]`       |
| 3 |     0     |      `[1,2,3]`      |

So at the end, the children array (in total) has 4 rows, but only 1 of the rows has any values (the first one). This is what it looks like in total:

```c++
[
  [1,2,3], // Children of Node 0
  [],      // Children of Node 1
  [],      // Children of Node 2
  []       // Children of Node 3
]
```

Then we want to run DFS from the root node

* Node 0
`longestChain = 0`
`secondLongestChain = 0`

We loop through the children of `0` and run dfs from node `1`

* Node 1
`longestChain = 0`
`secondLongestChain = 0`

We loop through all the children of `1`, but there is none. We update the currLongestPath to be the maximum between itself (`0`) and `longestChain + secondLongestChain + 1 = 0 + 0 + 1 = 1`. We finally return `longestChain + 1 = 0 + 1 = 1`

* Node 0
`longestChain = 0`
`secondLongestChain = 0`

Since `s[0] == s[1] --> a == a`, we don't do anything and just continue to the next child

We run dfs from node `2`

* Node 1
`longestChain = 0`
`secondLongestChain = 0`

We loop through all the children of `2`, but there is none. We update the currLongestPath to be the maximum between itself (`1`) and `longestChain + secondLongestChain + 1 = 0 + 0 + 1 = 1`. We finally return `longestChain + 1 = 0 + 1 = 1`

* Node 0
`longestChain = 0`
`secondLongestChain = 0`

Since `s[0] != s[2] --> a != b`, we update the longestChain to be `1` and secondLongestChain to be `0` (no change) and continue to the next child

We run dfs from node `3`

* Node 3
`longestChain = 0`
`secondLongestChain = 0`

We loop through all the children of `3`, but there is none. We update the currLongestPath to be the maximum between itself (`1`) and `longestChain + secondLongestChain + 1 = 0 + 0 + 1 = 1`. We finally return `longestChain + 1 = 0 + 1 = 1`

* Node 0
`longestChain = 1`
`secondLongestChain = 0`

Since `s[0] != s[3]`, we only update the secondLongestChain to be `1` and continue to the next child

There are no more children for node `0`, so we just update `currentLongestPath` to be the max between itself and `longestChain + secondLongestChain + 1 = 1 + 1 + 1 = 3`

* Aftermath

We return to the `longestPath` function and return `currLongestPath = 3` which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**