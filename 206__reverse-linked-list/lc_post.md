Title: C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

**NOTE TO READER: There is a clean solution at the bottom and a link to another solution**

# Intuition

Create a new linked list and keep track of the front of the new list and the back of the old list. Continuously move items from the back of the old list to the front of the new one and return once the old list is empty.

# Approach

First, we need to ensure that there are at least 2 elements in the list. If not, we can just return the head since nothing needed to be reversed.

Then, I set up the algorithm by:
1. Setting the new head equal to the second element
2. Setting a temporary pointer equal to the original head
3. Updating the head to be the 3rd element in the list
4. Updating the new head's next value to be the temporary pointer since it needs to go to the back of the new list
5. Updating the temporary pointers next to be `nullptr` since it is now at the end of the list

This is a challenging problem so lets just do the first example with nodes `[1,2,3,4,5]`:
1. Set the new head equal to `2`
2. Set a tmp pointer equal to `1`
3. Update the head of the list to be `3`
4. Update `2`'s next value to be `1`
5. Update the tmp pointer (`1`) next to be `nullptr`

This yields us the state `[3,4,5]` of the original list and `[2,1]` in the new list

Now we can iterate through the remainder of the list by pushing the first element in the old list onto the new list and moving the old list's pointer down one. We continue this process until we have iterated through the old list

# Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

# Code

```c++
ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return head;

        ListNode* new_head = head->next, *old_head = head;
        head = new_head->next;
        new_head->next = old_head;
        old_head->next = nullptr;
        while (head != nullptr) {
            old_head = new_head;
            new_head = head;
            head = head->next;
            new_head->next = old_head;
        }

        return new_head;
    }
```

# Cleaner Code

[Here is a link to a good explanation](https://leetcode.com/problems/reverse-linked-list/solutions/803955/c-iterative-vs-recursive-solutions-compared-and-explained-99-time-85-space/?envType=study-plan&id=level-1&orderBy=most_votes)

```c++
ListNode* reverseList(ListNode* head) {
        ListNode* next, *prev = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
```