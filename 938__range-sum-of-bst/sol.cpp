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

#define IN_RANGE(val, low, high) (((val) >= (low)) && ((val) <= (high)))

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *curr = st.top();
            st.pop();
            if (curr == nullptr)
                continue;

            if (IN_RANGE(curr->val, low, high)) {
                ans += curr->val;
                st.push(curr->left);
                st.push(curr->right);
            } else if (curr->val < low)
                st.push(curr->right);
            else
                st.push(curr->left);
        }

        return ans;
    }

    // Note to reader, this is just a recursive example
    int rangeSumBST_recursive(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return 0;

        if (IN_RANGE(root->val, low, high))
            return root->val + 
                   rangeSumBST(root->left, low, high) + 
                   rangeSumBST(root->right, low, high);

        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        
        return rangeSumBST(root->left, low, high);
    }
};