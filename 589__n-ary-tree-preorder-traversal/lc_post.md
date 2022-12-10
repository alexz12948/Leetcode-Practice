C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Use DFS with preorder traversal and keep track of the nodes that are visited

A pre-order traversal means that you first add yourself, then you add the children recursively from the left child to the right child

# Approach

I will provide code for both the recursive and iterative solution, but I will only explain the recursive.

For DFS, if the node is `nullptr`, we want to just return since there is nothing we can do with it. Then, we want to push back the current node's value and then loop through the children and call dfs on each one in order. This allows us to visit the node then all of its children from left to right recursively

We run DFS from the root and keep the answer array in the global space so it is easily accessable

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

# Recursive Code

```c++
class Solution {
public:
    vector<int> ans;

    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
private:
    void dfs(Node* node) {
        if (node == nullptr) return;
        ans.push_back(node->val);
        vector<Node*> c = node->children;
        for (int i = 0; i < c.size(); i++)
            dfs(c[i]);
    }
};
```

# Iterative Code

```c++
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            if (st.top() == nullptr) {
                st.pop();
                continue;
            }

            ans.push_back(st.top()->val);
            vector<Node*> c = st.top()->children;
            st.pop();
            for (int i = c.size() - 1; i >= 0; i--)
                st.push(c[i]);
        }

        return ans;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**