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

* If they are both `nullptr`, return `true`
* If they don't have the same value, return `false`
* Recurse and determine subtree validity (do the checks above again)

## Code

```c++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr)
            return p == q;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) || isSameTree(p->right, q->right);
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

We want to compare nodes in parallel and see if they are the same. If they are the same, then we want to check if the left/right subtrees are the same. Therefore, we just need to ensure that both nodes are null at the same time or they hold the same value. If they are both not null and have the same value, then we want to recursively check the left/right subtrees against each other

## Approach 

First, we check to see if the nodes are `nullptr`. If either of them are `nullptr`, then we just need to make sure that they are both `nullptr` for us to return `true`

Next, we check that the same value is held in the node (since we know neither of the nodes are `nullptr` now). If they don't have the same value, return `false`

Finally, we just recursively check the same properties on the left subtree and then the right subtree. If both of them are the same, then we want to return `true`

## Example

Lets use the first example, where `p = [1,2,3]` and `q = [1,2,3]`

* p = 1 and q = 1

They are both not null and they hold the same value, so we check the left subtree --> p->left = 2 and q->left = 2 are parameters

* p = 2 and q = 2

They are both not null and they hold the same value, so we check the left subtree -->
p->left = `nullptr` and q->left = `nullptr` are parameters

* p = `nullptr` and q = `nullptr`

Both nodes are null, so we return `true`

* p = 2 and q = 2

Now we check the right subtree --> p->right = `nullptr` and q->right = `nullptr` are parameters

* p = `nullptr` and q = `nullptr`

Both nodes are null, so we return `true`

* p = 2 and q = 2

Since the left and right subtree returned `true`, we want to continue to return `true`

* p = 1 and q = 1

Now we check the right subtree --> p->right = 3 and q->right = 3 are parameters

* p = 3 and q = 3

They are both not null and they hold the same value, so we check the left subtree -->
p->left = `nullptr` and q->left = `nullptr` are parameters

* p = `nullptr` and q = `nullptr`

Both nodes are null, so we return `true`

* p = 3 and q = 3

Now we check the right subtree --> p->right = `nullptr` and q->right = `nullptr` are parameters

* p = `nullptr` and q = `nullptr`

Both nodes are null, so we return `true`

* p = 3 and q = 3

Since the left and right subtree returned `true`, we want to continue to return `true`

* p = 1 and q = 1

Since the left and right subtree returned `true`, we want to continue to return `true`

* Aftermath

Since that was the last recursive call, we just return `true`, which is the correct answer

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**