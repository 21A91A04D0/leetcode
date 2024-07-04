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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp = head;
        ListNode *f = temp;
        head = head->next;
        int sm = 0;
        ListNode* prev;
        while(head) {
            if(head->val != 0) {
                sm += head->val;
                head = head->next;
            }
            else {
                temp->val = sm;
                prev = temp;
                ListNode *front = temp->next;
                temp = front;
                head = head->next;
                sm = 0;
            }
        }
        prev->next = nullptr;
        
        

        return f;
    }
};