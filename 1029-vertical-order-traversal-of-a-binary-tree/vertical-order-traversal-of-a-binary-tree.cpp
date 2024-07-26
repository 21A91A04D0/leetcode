/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>> >q;
        map<pair<int, int>, multiset<int> > mp;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode * nn = it.first;
            int r = it.second.first;
            int c = it.second.second;
            mp[{r,c}].insert(nn->val);
            if(nn->left) {
                q.push({nn->left,{r + 1, c - 1}});
            }
            if(nn->right) {
                q.push({nn->right, {r + 1, c + 1}});
            }
        }
        
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(auto it : mp) {
            mx = max(mx, it.first.second);
            mn = min(mn, it.first.second);
        }
        vector<vector<int> > ans(mx + abs(mn) + 1);
        for(auto it : mp) {
            int c = it.first.second;
            for(auto ele : it.second) {
                ans[c+abs(mn)].push_back(ele);
            }
        }
        return ans;
    }
};