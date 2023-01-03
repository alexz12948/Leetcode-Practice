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

#define IS_LEAF(r) ((r)->left == nullptr && (r)->right == nullptr)

class Solution {
    vector<int> find_leaf_value_seq(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            if (IS_LEAF(curr)) {
                ans.push_back(curr->val);
                continue;
            }

            if (curr->right != nullptr) st.push(curr->right);
            if (curr->left != nullptr)  st.push(curr->left);
        }

        return ans;
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return find_leaf_value_seq(root1) == find_leaf_value_seq(root2);
    }
};