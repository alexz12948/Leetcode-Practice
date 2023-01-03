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

* If the list is less than 3 values, just return `head` since nothing needs to be done
* Create 2 pointers to traverse the odd/even list and 1 more for the head of the even list
* Use the two traversal pointers to weave the list together
* At the end, just have the end of the odd list to point to the head of the even list and return

## Code

```c++
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

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

We partition the linked list in place based on odd/even nodes and we keep track of the first even node. Once the partitioning is finished, then we just connect the odd list to the even list and return.

## Approach 

The base case is if there is either 0, 1, or 2 elements in the list, then we can return the head since it is already an oddEven list

After that, we keep track of the first even node (`head->next`) and setup our pointers to point at the `head` and the `head->next`'s node

We then update the node's next pointers properly and move the pointers down the list until either the odd pointers next node is null (aka `even == nullptr`) or the even pointers next node is null (which would make odd_ptr null in the next iteration).

Once the loop breaks, we know that the even head points to the first even element and the pointers updated the lists so that we broke them apart into the odd and even partition. The last step is to make the last odd node point to the head of the even list (`odd_ptr->next = even_head`) and return

## Example

Lets use the first example, where `head = [1,2,3,4,5]`

We initialize:
* `even_head = 2`
* `odd_ptr = 1`
* `even_ptr = 2`

Now we iterate until the we are at the end of either the even or odd traversing pointers

* Iteration 1
`head = [1,2,3,4,5]`
`even_head = [2,3,4,5]`

`odd_ptr->next = even_ptr->next = 3`
`even_ptr->next = odd_ptr->next->next = 4`
`odd_ptr = odd_ptr->next = 3`
`even_ptr = even_ptr->next = 4`

* Iteration 2
`head = [1,3,4,5]`
`even_head = [2,4,5]`

`odd_ptr->next = even_ptr->next = 5`
`even_ptr->next = odd_ptr->next->next = nullptr`
`odd_ptr = odd_ptr->next = 5`
`even_ptr = even_ptr->next = nullptr`

* Termination
Since `odd_ptr->next = nullptr`
`head = [1,3,5]`
`even_head = [2,4]`

Finally, `odd_ptr->next = even_head`, which links the two lists together yielding:

`[1,3,5,2,4]` which is the correct answer!

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**