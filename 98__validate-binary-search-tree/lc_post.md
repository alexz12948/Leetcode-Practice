C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

We want to recursively determine whether each subtree is valid to determine whether or not the entire BST is valid

# Approach

We need to keep track of the smallest node and largest node as we traverse. If the current node is null, then we return true since null nodes are valid BSTs. 

Then, we compare the node's value to the low and high and if it is equal to or exceeds the values, we return false. The reason why is because if the node's value is lower than the current lowest value, then that means somewhere above that node in the tree is a value that it is less than or equal to, which breaks the properties of a BST

Otherwise, we want to recursively call the `isValidSubtree` function on the left and right subtree. For the left, we want to pass in the current low for the low and the current node for the high since the current node becomes the new greatest node in the subtree. For the right, we want to pass in the current high for the high and the current node for the low since the current node becomes the new smallest node in the subtree.

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

# Code

```c++
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
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**