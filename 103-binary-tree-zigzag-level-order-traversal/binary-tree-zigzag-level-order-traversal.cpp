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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> ans;

            for(int i = 0 ; i < sz; i++) {
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                ans.push_back(q.front()->val);
                q.pop();
            }
            if(cnt % 2 == 0) {
                v.push_back(ans);
            }
            else {
                reverse(ans.begin(), ans.end());
                v.push_back(ans);
            }
            cnt++;
        }
        return v;
    }
};