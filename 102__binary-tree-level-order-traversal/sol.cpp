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
    vector<vector<int>> ans;

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
private: 
    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) return;
        if (ans.size() < depth) {
            ans.push_back(vector<int>());
        }
        ans[depth - 1].push_back(node->val);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};