Title: C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

First, we need to determine whether or not there is a cycle. Once that is determined then we need to find the node where the cycle begins.

# Approach

First we need to determine whether or not there is a cycle. To do this, we can just use a slow and fast pointer where the slow pointer moves 1 node down the list and the fast pointer moves 2. If the fast pointer is ever `nullptr` or the fast pointer's next node is `nullptr`, then we know there is no cycle (since there is an end to the list). However, if the slow pointer ever equals the fast pointer, then we know that a cycle must occur.

Now is the math-y part of this problem, so let me first start by defining some values:
* Let $$d_1$$ be the distance from the head of the list to the start of the cycle
* Let $$d_2$$ be the distance from the start of the cycle to the point where the fast and slow pointers meet
* Let $$C$$ be the length of the cycle

We know that the fast pointer traveled $$2* (d_1 + d_2)$$ steps while the slow pointer traveled $$(d_1 + d_2)$$ steps (check if for yourself if you are having difficulty understanding). We also know that the extra distance that the fast pointer traveled $$d_1 + d_2$$ must be a multiple of the cycle's length. $$\therefore d_1 + d_2 = N * C$$ where $$N$$ is just some positive constant ($$N \in \natnums$$).

Since $$d_1 + d_2 = N * C \rightarrow d_1 = N*C - d_2$$, then if we let the slow pointer go $$d_1$$ steps, it will arrive at the front of the cycle. Additionally, if we go from the head of the list and move $$d_1$$ steps, it will also arrive at the front of the cycle.

If we iterate the slow pointer from the node where slow met fast $$d_1$$ steps and we move another pointer from the head down the list $$d_1$$ steps, we know that when they meet, it will be the point at the start of the cycle. When they meet, we return either pointer

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (slow != fast) return nullptr;

        while (slow != head) {
            slow = slow->next;
            head = head->next;
        }

        return slow;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**