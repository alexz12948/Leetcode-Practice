Title: C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Have 2 pointers where 1 is going 2x the speed of the other (2 nodes at a time opposed to 1 node at a time). If there is a cycle the fast one will catch up to the slow one. If there isn't a cycle, the fast one will reach the end of the list

# Approach

Create two pointers that are both initially looking at the head of the list. Then, you must ensure that the fast pointer will not access out of bound (`fast != nullptr && fast->next != nullptr`). Then move the slow pointer forward 1 node and the fast pointer forward 2 nodes. If `slow == fast` then we know that the fast had to have looped around to get to slow so we return true. If the loop finishes, that means that the fast pointer found the end of the list and we can return false

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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) 
                return true;
        }

        return false;
    }
};
```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**