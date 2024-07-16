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
    ListNode* reverse(ListNode*root) {
        ListNode *temp = root, *prev = NULL;
        while(root) {
            ListNode *front = root->next;
            root->next = prev;
            prev = root;
            root = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return false;
        ListNode *fast = head, *slow = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *h2 = reverse(slow);
        while(h2 and head) {
            if(h2->val != head->val) return false;
            h2 =  h2->next;
            head = head->next;
        }

        return true;
    }
};