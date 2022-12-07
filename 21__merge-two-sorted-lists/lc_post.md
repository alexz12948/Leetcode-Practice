Title: C++ || Easy to Understand with In-Depth Explanation || O(N)

# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁

# Intuition

Loop through both lists at the same time and take the node that has the smaller value at push it to the back of the merged list. Once one of them runs out of values, then push the remainder of the other list on.

# Approach

First, we need to deal with the case of if one of the lists have no values. If that is the case, then just return the other list. For example, if `list1 == nullptr`, then return `list2`, regardless of whether or not it has nodes.

Then we need to find the `newHead` of the list. In order to do that, we find which head node is lower between the two lists, use that as the `newHead` and move that list's head down one.

Finally, we create a pointer to keep track of the last element in the new list and we iterate while both lists are not empty. If `list1`'s value is less than or equal to `list2`, then we set `list1`'s node to be the next in the new list and we move that head down. Otherwise, we set `list2`'s node to be next in the new list. Then, we just move the pointer on the last element on the new list down one.

Once that loop finishes, either `list1` is empty, `list2` is empty, or both are empty. If either of them aren't empty, then we want to push the remainder of that list onto the new list. Once that is completed, we have merged them and we can return

# Complexity

**Time Complexity:** $$O(N)$$ where n is the length of the longer list
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        ListNode* new_head;
        if (list1->val <= list2->val) {
            new_head = list1;
            list1 = list1->next;
        } else {
            new_head = list2;
            list2 = list2->next;
        }
        
        ListNode* last_elem = new_head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                last_elem->next = list1;
                list1 = list1->next;
            } else {
                last_elem->next = list2;
                list2 = list2->next;
            }

            last_elem = last_elem->next;
        }

        if (list1 != nullptr)
            last_elem->next = list1;
        else
            last_elem->next = list2;

        return new_head;
    }
};
```