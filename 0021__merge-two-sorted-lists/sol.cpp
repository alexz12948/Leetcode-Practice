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