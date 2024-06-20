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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newNode = new ListNode(-1);
        ListNode *temp = newNode;
        ListNode *l1 = list1, *l2 = list2;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                newNode->next = l1;
                l1 = l1->next;
            }
            else {
                newNode->next = l2;
                l2 = l2->next;
            }
            newNode = newNode->next;
        }
        while(l1) {
            newNode->next = l1;
            l1 = l1->next;
            newNode = newNode->next;
        }
        while(l2) {
            newNode->next = l2;
            l2 = l2->next;
            newNode = newNode->next;
        }
        return temp->next;
    }
};