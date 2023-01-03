Title: C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Find the leaf value sequence for each of the trees and return whether or not they are equal

# Approach

In order to find the leaf value sequence, I chose to do an iterative dfs that always goes to the left before the right. Since we are using a stack, we must always push the right child on first before the left so the left will be popped off/explored prior to the right (which is the behavior we want). If the node is a leaf, then we push back the answer's value and then continue. Since we are only looking for leaves, I ensure that all of the values on the stack are not nullptr so we don't have to excessively push values onto the stack.

# Complexity

**Time Complexity:** $$O(N)$$ where N is the number of nodes in the tree
**Space Complexity:** $$O(N)$$

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
```