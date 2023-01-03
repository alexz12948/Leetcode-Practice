C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)

# TL;DR

Continuously push the smaller of the two heads of the lists until one list is empty. Then, push the rest of the non-empty list onto the end

## Code

```c++
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

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

Loop through both lists at the same time and take the node that has the smaller value at push it to the back of the merged list. Once one of them runs out of values, then push the remainder of the other list on.

## Approach 

First, we need to deal with the case of if one of the lists have no values. If that is the case, then just return the other list. For example, if `list1 == nullptr`, then return `list2`, regardless of whether or not it has nodes.

Then we need to find the `newHead` of the list. In order to do that, we find which head node is lower between the two lists, use that as the `newHead` and move that list's head down one.

Finally, we create a pointer to keep track of the last element in the new list and we iterate while both lists are not empty. If `list1`'s value is less than or equal to `list2`, then we set `list1`'s node to be the next in the new list and we move that head down. Otherwise, we set `list2`'s node to be next in the new list. Then, we just move the pointer on the last element on the new list down one.

Once that loop finishes, either `list1` is empty, `list2` is empty, or both are empty. If either of them aren't empty, then we want to push the remainder of that list onto the new list. Once that is completed, we have merged them and we can return

## Example

Let's use Example 1, where `list1 = [1,2,4]` and `list2 = [1,3,4]`

![Example 1 Image](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

First, we choose the minimum between the two heads of the list. Since they have the same value, I arbitrarily chose the first element of list1 to be the head. Then, we move the head of list1 forward by 1. Here is what current state looks like before we loop:

`new_list = [1]`

| list1 iterator |     | it1 |   |   |
|----------------|-----|-----|---|---|
| list1          | 1   | 2   | 4 |   |
| list2          | 1   | 3   | 4 |   |
| list2 iterator | it2 |     |   |   |

Then, we keep track of the back of the new list and we continuously push the smaller of the two elements onto the new list.

* `it1 > it2 --> 2 > 1`: We push the head of the second list (`1`) onto the new list and move the head forward

`new_list = [1,1]`

| list1 iterator |   | it1 |   |   |
|----------------|---|-----|---|---|
| list1          | 1 | 2   | 4 |   |
| list2          | 1 | 3   | 4 |   |
| list2 iterator |   | it2 |   |   |

* `it1 < it2 --> 2 < 3`: We push the head of the first list (`2`) onto the new list and move the head forward

`new_list = [1,1,2]`

| list1 iterator |   |     | it1 |   |
|----------------|---|-----|-----|---|
| list1          | 1 | 2   | 4   |   |
| list2          | 1 | 3   | 4   |   |
| list2 iterator |   | it2 |     |   |

* `it1 > it2 --> 4 > 3`: We push the head of the second list (`3`) onto the new list and move the head forward 

`new_list = [1,1,2,3]`

| list1 iterator |   |   | it1 |   |
|----------------|---|---|-----|---|
| list1          | 1 | 2 | 4   |   |
| list2          | 1 | 3 | 4   |   |
| list2 iterator |   |   | it2 |   |

* `it1 == it2 --> 4 == 4`: We push either head onto the new list (`4`). In my case, I chose list1 and we move list1's head forward.

`new_list = [1,1,2,3,4]`

| list1 iterator |   |   |     | it1 |
|----------------|---|---|-----|-----|
| list1          | 1 | 2 | 4   |     |
| list2          | 1 | 3 | 4   |     |
| list2 iterator |   |   | it2 |     |

Since list1 is now empty, we just push the remainder of list2 (`[4]`) onto the new list and return

At the end, we have the new list containing `[1,1,2,3,4,4]`, which is exactly what we want

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**