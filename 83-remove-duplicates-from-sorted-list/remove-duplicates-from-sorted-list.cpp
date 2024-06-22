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
        ListNode *node = new ListNode(head->val);
        ListNode *a = node;
        int temp = head->val;
        head = head->next;
        while(head) {
            if(head->val != temp)  {
                temp = head->val;
                node->next = head;
                node = node->next;
            }
            head = head->next;
        }
        node->next = nullptr;
        return a;
    }
};