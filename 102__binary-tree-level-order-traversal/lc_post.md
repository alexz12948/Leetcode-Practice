C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Use a modified DFS that takes into account the current nodes depth

# Approach

If the current number of levels is less than the current depth (`ans.size() < depth`), then we need to create another level of depth to hold the nodes values. For every node that we see, we push back the value at the appropriate depth and we recurse going from left to right.

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

# Code

```c++
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
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**