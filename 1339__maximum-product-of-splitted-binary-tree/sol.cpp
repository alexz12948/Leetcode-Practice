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

typedef long long ll;

class Solution {
public:
    ll ans = 0, totalSum = 0;

    int maxProduct(TreeNode* root) {
        totalSum = total_tree_sum(root);
        subtree_sum_product(root);
        return ans % int(1e9 + 7);
    }
private:
    int total_tree_sum(TreeNode* node) {
        if (node == nullptr) return 0;
        return total_tree_sum(node->left) + total_tree_sum(node->right) + node->val;
    }

    int subtree_sum_product(TreeNode* node) {
        if (node == nullptr) return 0;
        int currSum = subtree_sum_product(node->left) +
                      subtree_sum_product(node->right) +
                      node->val;
        ans = max(ans, (totalSum - currSum) * currSum);
        return currSum;
    }
};