Title: C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Find the minimum and maximum within each subtree and return the greatest difference when reaching a leaf

# Approach

The best idea is to use a modified dfs that takes in a node and the current min/max. After that we just want to call this dfs from the original function with the root and the root's value as the min and max.

Then, we need the base case for DFS, which is when the node is null. In that case we should just return the difference between the max and min values.

If the node isn't null, we should take the min between the parameter and the node's value and the max between the parameter and the node's value. After that we want to return the max of dfs'ing on the left subtree and the right subtree.

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$ with an unbalanced binary tree, best case would be $$O(logN)$$

# Code

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int dfs(TreeNode* node, int curr_min, int curr_max) {
        if (node == nullptr)
            return curr_max - curr_min;

        curr_min = min(curr_min, node->val);
        curr_max = max(curr_max, node->val);
        return max(dfs(node->left, curr_min, curr_max), 
                   dfs(node->right, curr_min, curr_max));
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**