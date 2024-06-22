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
    int get_length(ListNode *head) {
        int cnt = 0;
        while(head) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode *reverseList(ListNode *temp1) {
        ListNode *prev = nullptr, *front;
        while(temp1) {
            front = temp1->next;
            temp1->next = prev;
            prev = temp1;
            temp1 = front;
        }
        return prev;
    }
    void insertAtEnd(ListNode *pot) {
        while(pot->next) {
            pot = pot->next;
        }
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int len = 0;
        ListNode *temp = head;
        ListNode *j = head;
        ListNode *res = new ListNode(-1);
        ListNode *a = res,*front;
        while(head) {
            len++;
            if(len % k == 0) {
                front = head->next;
                head->next = nullptr;
                ListNode *rev = reverseList(j);
                j = front;
                head = front;
                res->next = rev;
            }
            
            else head = head->next;
            while(res->next) {
                res = res->next;
            }
        }
        if(front != NULL) {
            res->next = front;
        }
        return a->next;
    }
};