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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *nn = new ListNode(-1);
        ListNode *n = nn;
        ListNode *prev = head;

        if(head->val != head->next->val) {
            nn->next = head;
            nn = nn->next;
        }
        head = head->next;
        ListNode *front;
        while(head->next) {
            if(prev->val != head->val and head->val != head->next->val) {
                nn->next = head;
                nn = nn->next;
            }
            prev = head;
            front = head->next;
            head->next = NULL;
            head = front;
        }
        
        if(prev->val != head->val) {
            nn->next = head;
            nn = nn->next;
        }
        else {
            nn->next = NULL;
        }
        // cout << head->val << " " << prev->val << " ";
        
        return n->next;
    }
};