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
    ListNode *reverse(ListNode *root) {
        ListNode *prev = NULL;

        while(root) {
            ListNode *front = root->next;
            root->next = prev;
            prev = root;
            root = front;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *ptr1 = head, *ptr2 = head,*prev = nullptr;
        left--,right--;
        if(left == right) return head;
        while(left--)  {
            prev = ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            right--;
        }
        // right -= left;
        while(right--) {
            ptr2 = ptr2->next;
      
        }
        ListNode *front = ptr2->next;
    ptr2->next = NULL;
    ListNode *newHead = reverse(ptr1);

    if (prev) {
        prev->next = newHead;
    } else {
        head = newHead;
    }

    while (newHead->next) {
        newHead = newHead->next;
    }
    newHead->next = front;

    return head;
    }
};