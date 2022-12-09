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