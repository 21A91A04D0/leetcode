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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }
        map<int, int> mp;
        mp[0] = -1;
        int prefix = 0;
        vector<pair<int, int>> v;
        int i = 0;
        while(i < arr.size()) {
            prefix += arr[i];
            if(mp.find(prefix) != mp.end()) {
                v.push_back({mp[prefix],i});
            }
            mp[prefix] = i;
            i++;
        }
        sort(v.begin(), v.end());
        vector<pair<int, int>> ans;
        int k = 0;
        int j = 1;
        if(v.size() > 0) {
            ans.push_back(v[0]);
            while(j < v.size()) {
                int left = ans[k].second;
                if(v[j].first + 1 > left) {
                    ans.push_back(v[j]);
                    k++;
                }
                j++;
            }
        }
        for(auto it : ans) {
            for(int i = it.first + 1 ; i <= it.second ; i++) {
                arr[i] = 0;
            }
        }
        ListNode* n = new ListNode(-1);
        ListNode* tem = n;
        for(auto it : arr) {
            if(it != 0) {
                ListNode* nn = new ListNode(it);
                n->next = nn;
                n = nn;
            }
        }
        return tem->next;
    }
};