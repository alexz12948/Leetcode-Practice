Title: C++ || Easy to Understand with In-Depth Explanation || O(N)
Tags: cpp, c++, easy-understanding, clean code, beginner, beginner friendly, easy

### PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

### Intuition

You can use 2 pointers to be able to find the middle element in linear time. The idea is that one of the pointers iterates through each node while the other pointer iterates at double the speed. When the pointer that is double speed is null or the last element in the list, then you know that curr must be at the end. 

Let's break this down into two cases: when the list length is even and when it is odd

**Even -** when this occurs, then by iterating the double pointer it will `NULL` when it terminates since the linked list starts on an odd number. For the test case with node values of `[1,2,3,4,5,6]`, the double pointer will be at node 1, then 3, then 5, then NULL. Then the normal pointer will be at node 1, then 2, then 3, then 4 since the double pointer jumped three times. We return the node that the normal pointer is pointing to

**Odd -** when this occurs, then by iterating the double pointer normally, it will land on the last element when it terminates since the linked list starts on an odd number and finishes on an odd number. For the test case with node values of `[1,2,3,4,5]`, the double pointer will be at node 1, then 3, then 5 and stop. Then the normal pointer will be at node 1, then 2, then 3 and stop. We return the node that the normal pointer is pointing to as well.

### Approach

Initialize the normal pointer and the double pointer to be at the head. Then, while the double_pointer is not null AND the double pointer's next value is not null (that would mean it would be the last element), then move the current pointer over 1 and the double pointer over twice. At the end, just return the current pointer

### Complexity

**Time Complexity:** O(n) where n is the length of the list
**Space Complexity:** O(1)

### Code

```c++
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *curr = head, *double_curr = head;

        while (double_curr != NULL && double_curr->next != NULL) {
            curr = curr->next;
            double_curr = double_curr->next->next;
        }

        return curr;
    }
};
```