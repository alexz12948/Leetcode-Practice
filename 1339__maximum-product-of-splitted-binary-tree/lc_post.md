C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Find the total sum of the tree first, then do a post-traversal DFS and find the greatest product of this subtree's sum and it's complement. 

For example, if the total sum is 10 and the current sum is 3 (as we are traversing using DFS), then we know that the product is $$3 * (10 - 3) = 3 * 7 = 21$$

# Approach

Note that for this, it was just easier to pass around global variables, however one could easily just store them for each call and pass around the variables. I would probably make `totalSum` and `ans` local to `maxProduct` and pass `ans` in by reference to be able to update it outside of the function call

First we need to calculate the total sum of all the nodes in the entire tree. This is a simple DFS (doesn't matter the traversal order)

Then we want to do a post order traversal (going from the leaves back to the root) and keep track of the current. We know that the product of 2 subtrees is the product of the current sum of the current subtree and its complement. We can take the complement by taking the difference between the total sum and the current sum. All we need then is to keep track of the best product and return that value mod `1e9 + 7`

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$ in the worst case of an unbalanced binary tree. $$O(logN)$$ in a completely balanced binary tree

# Code

```c++
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
```

# Another good solution

If you want to see how another user does it using only 1 function (but with the same idea), look [here](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/solutions/1412813/c-java-python-post-order-dfs-clean-concise/?orderBy=most_votes)

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**