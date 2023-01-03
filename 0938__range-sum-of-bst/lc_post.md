Title: C++ || Iterative and Recursive || Easy to Understand with In-Depth Explanation || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

The idea is to look at the current elements value and if it is in the range, then add it onto the total and look at both the left and right subtree. 

If it is lower than the range, we only want to look at the right subtree since those values might be in the range. 

If it is greater than the range, we only want to look at the left subtree since those values might be in the range.

# Approach

We want to use a modified DFS, for which are two different approaches that can be used: iterative or recursive. I will be mainly talking about the iterative approach, but I wrote a recursive solution below for those who are curious

In order to implement a DFS iteratively, we need to use a stack. Then we pop the top element off of the stack and check that it isn't null since if it is, it isn't a valid node and we just continue to iterate

If the top element's value is in the range `[low,high]`, then we add it to the sum and push both the left and right subtree nodes since they could both be in the range.

If the top element's value is lower than the range (`curr->val < low`), then we push only the right subtree node since only their values could be in the range since we are looking for larger values than the current one.

If the top element's value is greater than the range (`curr->val > high`), then we push only the left subtree node since only their values could be in the range since we are looking for smaller values than the current one.

# Complexity

**Time Complexity:** $$O(N)$$
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
```