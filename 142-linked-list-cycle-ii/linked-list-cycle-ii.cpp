/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        while(fast && fast->next) {
            
            slow = slow->next;

            fast = fast->next->next;

            if(slow == fast) {
                while(prev != slow) {
                    prev = prev->next;
                    slow = slow->next;
                }
                return slow;
            }
            
        }
        return NULL;
    }
};