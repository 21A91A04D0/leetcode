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
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *front;
        while(head) {
            front = head->next;
            head->next = prev;
            prev = head;
            head = front;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *rev = reverse(head);
        ListNode *prev = nullptr,*t = rev;
        if(n == 1) {
            t = t->next;
        }
        else {
            n--;
            while(n) {
                prev = rev;
                rev = rev->next;
                n--;
            }
            prev->next = rev->next;
        }
        ListNode *f = reverse(t);
        return f;

    }
};