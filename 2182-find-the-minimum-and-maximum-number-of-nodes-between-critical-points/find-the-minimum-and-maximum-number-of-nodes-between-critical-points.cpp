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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        int pos = 1;
        ListNode *prev = head, *front;
        head = head->next;
        vector<int> p;
        if (!head || !head->next || !head->next->next)
            return ans;
        while(head->next != NULL) {
            pos++;
            front = head->next;
            if (front->val < head->val && prev->val < head->val || front->val > head->val and prev->val > head->val) {
                p.push_back(pos);
            }
            prev = head;
            head = head->next;
        }
        for(auto it : p) cout << it << " ";
        if(p.size() < 2) return {-1,-1};
        int mn = INT_MAX;
        for(int i = 1; i < p.size(); i++) {
            mn = min(mn, p[i] - p[i - 1]);
        }
        int mx = p[p.size() - 1] - p[0];
        
        return {mn,mx};
    }
};