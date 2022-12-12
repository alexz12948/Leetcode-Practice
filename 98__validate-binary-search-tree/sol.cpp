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
    bool isValidBST(TreeNode* root) {
        return isValidSubtree(root, nullptr, nullptr);
    }
private:
    bool isValidSubtree(TreeNode* node, TreeNode* low, TreeNode* high) {
        if (node == nullptr)
            return true;

        if ((low != nullptr && node->val <= low->val) ||
            (high != nullptr && node->val >= high->val))
            return false;

        return isValidSubtree(node->left, low, node) &&
               isValidSubtree(node->right, node, high);
    }
};