C++ || O(N) || Easy to Understand with In-Depth Explanation and Examples

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Use DFS from the root and perform these actions in order to ensure proper preorder traversal:

1. Push back the current node
2. Push the right node onto the stack
3. Push the left node onto the stack

## Code

```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            
            if (curr == nullptr)
                continue;

            ans.push_back(curr->val);
            st.push(curr->right);
            st.push(curr->left);
        }

        return ans;
    }
};
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(N)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We want to visit the nodes in this order:

* Current node
* The left subtree
* The right subtree

We can follow this approach by running dfs from the root since it has the behavior that we are looking for (go all the way down a path, then try alternative routes)

## Approach 

Use a stack and run dfs from the root. If the top node is `nullptr` then continue onto the next element on the stack. 

Then we push back the current value onto the answer array, and then push the right node then left node onto the stack. The reason why it is right then left is because we want to visit the left subtree first, so it needs to be the last node pushed onto the stack.

## Example

Lets use an example where `root = [1,2,3,4,5]`

We push the root onto the stack so we have the initial state:

Stack: `[1]` <-- TOP
Ans = `[]`

* Pop 1 off

We pop `1` off the stack and since it isn't `nullptr`, we push it onto `ans` and push the right `3` and then the left `2` onto the stack

Stack: `[3,2]` <-- TOP
Ans = `[1]`

* Pop 2 off

We pop `2` off the stack and since it isn't `nullptr`, we push it onto `ans` and push the right `5` and then the left `4` onto the stack

Stack: `[3,5,4]` <-- TOP
Ans = `[1,2]`

* Pop 4 off

We pop `4` off the stack and since it isn't `nullptr`, we push it onto `ans` and push the right `nullptr` and then the left `nullptr` onto the stack

Stack: `[3,5,nullptr,nullptr]` <-- TOP
Ans = `[1,2,4]`

* Pop `nullptr` off twice

We pop `nullptr` off the stack and continue and do it again since the next element is also `nullptr`

Stack: `[3,5]` <-- TOP
Ans = `[1,2,4]`

* Pop 5 off

We pop `5` off the stack and since it isn't `nullptr`, we push it onto `ans` and push the right `nullptr` and then the left `nullptr` onto the stack

Stack: `[3,nullptr,nullptr]` <-- TOP
Ans = `[1,2,4,5]`

* Pop `nullptr` off twice

We pop `nullptr` off the stack and continue and do it again since the next element is also `nullptr`

Stack: `[3]` <-- TOP
Ans = `[1,2,4,5]`

* Pop 3 off

We pop `3` off the stack and since it isn't `nullptr`, we push it onto `ans` and push the right `nullptr` and then the left `nullptr` onto the stack

Stack: `[nullptr,nullptr]` <-- TOP
Ans = `[1,2,4,5,3]`

* Pop `nullptr` off twice

We pop `nullptr` off the stack and continue and do it again since the next element is also `nullptr`

Stack: `[]` <-- TOP
Ans = `[1,2,4,5,3]`

* Aftermath

We return `[1,2,4,5,3]`, which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**