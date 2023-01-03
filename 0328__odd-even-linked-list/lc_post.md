Title: C++ || Easy to Understand with In-Depth Explanation || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

We partition the linked list in place based on odd/even nodes and we keep track of the first even node. Once the partitioning is finished, then we just connect the odd list to the even list and return.

# Approach

The base case is if there is either 0, 1, or 2 elements in the list, then we can return the head since it is already an oddEven list

After that, we keep track of the first even node (`head->next`) and setup our pointers to point at the `head` and the `head->next`'s node

We then update the node's next pointers properly and move the pointers down the list until either the odd pointers next node is null (aka `even == nullptr`) or the even pointers next node is null (which would make odd_ptr null in the next iteration).

Once the loop breaks, we know that the even head points to the first even element and the pointers updated the lists so that we broke them apart into the odd and even partition. The last step is to make the last odd node point to the head of the even list (`odd_ptr->next = even_head`) and return

# Complexity

**Time Complexity:** $$O(n)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr ||
            head->next == nullptr ||
            head->next->next == nullptr)
            return head;

        ListNode *even_head = head->next,
                 *odd_ptr = head,
                 *even_ptr = head->next;

        while (odd_ptr->next != nullptr && even_ptr->next != nullptr) {
            odd_ptr->next = even_ptr->next;
            even_ptr->next = odd_ptr->next->next;
            odd_ptr = odd_ptr->next;
            even_ptr = even_ptr->next;
        }
        odd_ptr->next = even_head;
        return head;
    }
};
```