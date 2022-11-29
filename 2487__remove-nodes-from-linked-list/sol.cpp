/*
Explanation of Solution
-----------------------

This algorithm is a modification on the first greater element
question

The idea is to use a stack to keep track of the first greater
element, however the stack at the end of the iteration should
have the list that we want, but in reverse order. Therefore,
use another stack to reverse the original stack and then create
a linked list from the elements

Complexity
----------
Time: O(n)
Space: O(1) 
*/
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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        st.push(head);

        while (head != nullptr) {
            while (!st.empty() && st.top()->val < head->val) {
                st.pop();
            }
            st.push(head);
            head = head->next;
        }

        stack<ListNode*> st2;
        while (!st.empty()) {
            st2.push(st.top());
            st.pop();
        }

        ListNode* newHead;
        ListNode* tmp;
        newHead = st2.top(), tmp = st2.top();
        st2.pop();
        while (!st2.empty()) {
            ListNode* next = st2.top();
            tmp->next = next;
            st2.pop();
            tmp = tmp->next;
        }

        tmp->next = nullptr;

        return newHead;
    }
};
