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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *nn = new ListNode(-1);
        ListNode *temp = new ListNode(-1),*t = nn;
        ListNode *t1 = temp;
        while(head) {
            if(head->val < x) {
                nn->next = head;
                nn = nn->next;
            }
            else {
                temp->next = head;
                temp = temp->next;
            }
            head = head->next;
        }
        nn->next = NULL;
        temp->next = NULL;
        if(t->next == NULL) return t1->next;
        if(t1->next == NULL) return t->next;
        t = t->next;
        ListNode *res = t;
        t1 = t1->next;
        while(t->next) {
            t = t->next;
        }
        t->next = t1;
        return res;
    }
};