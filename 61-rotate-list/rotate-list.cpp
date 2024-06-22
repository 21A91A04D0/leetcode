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
    ListNode* reverseList(ListNode *head) {
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
    int get_length(ListNode* head) {
        int cnt = 0;
        while(head) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int n = get_length(head);
        k = k % n;
        
        n = n - k - 1;
        ListNode *temp1 = head;
        ListNode *temp2;
        while(n--) {
            head = head->next;
        }
        temp2 = head->next;
        head->next = NULL;

        ListNode *rev1 = reverseList(temp1);
        ListNode *rev2 = reverseList(temp2);
        ListNode *rev3 = rev1;
        while(rev1->next) {
            rev1 = rev1->next;
        }
        rev1->next = rev2;
        ListNode *res = reverseList(rev3);
        return res;
    }
};