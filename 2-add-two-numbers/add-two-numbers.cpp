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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *nn = new ListNode(-1);
        ListNode *t = nn;
        int carry = 0;
        while(l1 && l2) {
            // cout << carry << " ";
            int sm = l1->val + l2->val + carry;
            carry = sm / 10;
            sm = sm % 10;
            
            
            ListNode *n1 = new ListNode(sm);
            nn->next = n1;
            nn = nn->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            int sm = l1->val + carry;
            carry = sm /10;
            sm = sm % 10;
            
            ListNode *n1 = new ListNode(sm);
            nn->next = n1;
            nn = nn->next;
            l1 = l1->next;
        }
        while(l2) {
            int sm = l2->val + carry;
            carry = sm /10;
            sm = sm % 10;
            ListNode *n1 = new ListNode(sm);
            nn->next = n1;
            nn = nn->next;
            l2 = l2->next;
        }
        if(carry) {
            ListNode *n1 = new ListNode(carry);
            nn->next = n1;
        }
        return t->next;
    }
};