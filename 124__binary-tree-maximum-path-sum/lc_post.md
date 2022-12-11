C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

*This was done in conjunction with [Andrea](https://leetcode.com/andreafoo11/)*

# Intuition

* Traverse the tree using a post order dfs
* Determine the maximum between the current best answer and the path that includes the node you are looking at
* Return the best path between looking at the left and looking at the right

# Approach

Keep a global answer which is initially `INT_MIN`

Then, traverse the graph until you get to a nullptr, which means that we just want to return 0. Then we figure out the max between the left path and 0 and the right path and 0, which is essentially finding the maximum between including the path or not. 

We update the answer to be the maximum between the current best and the path that goes from the left to the right through the current node (since that would be the end of the path)

Finally, we return the maximum path through the current node between the left path and the right path. At the end, we just want to return `ans` since it was being updated globally

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$ when the tree is unbalanced; best case is $$O(logN)$$

# Code

```c++
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
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**