C++ || Easy to Understand with In-Depth Explanation and Examples || O(N)

#### Table of Contents

- [TL;DR](#tldr)
  - [Code](#code)
  - [Complexity](#complexity)
- [In Depth Analysis](#in-depth-analysis)
  - [Intuition](#intuition)
  - [Approach](#approach)
  - [Example](#example)
- [Cleaner Code](#cleaner-code)

**NOTE TO READER: There is a clean solution at the bottom and a link to another solution**

# TL;DR

Create a new list and continuously move elements from the front of the original list to the front of the new list

## Code

```c++
class Solution {
public:
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
};
```

## Complexity

**Time Complexity:** $$O(N)$$
**Space Complexity:** $$O(1)$$

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

# In Depth Analysis

## Intuition

Create a new linked list and keep track of the front of the new list and the back of the old list. Continuously move items from the back of the old list to the front of the new one and return once the old list is empty.

## Approach 

First, we need to ensure that there are at least 2 elements in the list. If not, we can just return the head since nothing needed to be reversed.

Then, I set up the algorithm by:
1. Setting the new head equal to the first element
2. Moving the head forward by 1 (to the second element)
3. Setting the new head's next pointer equal to `nullptr` since it is the current end of the new lists

Now we can iterate through the remainder of the list by pushing the first element in the old list onto the new list and moving the old list's pointer down one. We continue this process until we have iterated through the old list

## Example

Let's use a list where `head = [1,2,3]`

First, we set the `new_head` to be `1` and initialize another pointer that we can use later. Then, we set `head` to be `2` and the `new_head`'s next to be `nullptr` since it is the end of the list

* We know that the original list still has values, so we set `old_head` to be `new_head` (`1`) since we want to keep track of the current first element of the new list. Then, `new_head` gets `head` (`2`: the current front of the list). Then, we move `head` down one value to `nullptr` and `new_head`'s next value to be `old_head` (`2`). Here is what the state looks like:

| head iterator |     |   | head |   |
|---------------|-----|---|------|---|
| original list | 1   | 2 | 3    |   |
| new list      | 2   | 1 |      |   |
| new iterator  | new |   |      |   |

* We know that the original list still has values, so we set `old_head` to be `new_head` (`2`) since we want to keep track of the current first element of the new list. Then, `new_head` gets `head` (`3`: the current front of the list). Then, we move `head` down one value to `3` and `new_head`'s next value to be `old_head` (`1`). Here is what the state looks like:

| head iterator |     |   |   | head |
|---------------|-----|---|---|------|
| original list | 1   | 2 | 3 |      |
| new list      | 3   | 2 | 1 |      |
| new iterator  | new |   |   |      |

Since the original list has no more values, we return `new_head`

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**

---

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