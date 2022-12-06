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