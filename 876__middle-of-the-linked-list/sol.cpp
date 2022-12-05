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
    ListNode* middleNode(ListNode* head) {
        ListNode *curr = head, *double_curr = head;

        while (double_curr != NULL && double_curr->next != NULL) {
            curr = curr->next;
            double_curr = double_curr->next->next;
        }

        return curr;
    }
};
