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
public:
    int ans = INT_MIN;

    int maxPathSum(TreeNode* root) {
        post_order_dfs(root);
        return ans;
    }
private:
    int post_order_dfs(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = max(post_order_dfs(node->left), 0);
        int right = max(post_order_dfs(node->right), 0);

        ans = max(ans, left + right + node->val);

        return max(left + node->val, right + node->val);
    }
};