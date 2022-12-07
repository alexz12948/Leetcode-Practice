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