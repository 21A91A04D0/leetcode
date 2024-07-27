/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void make_parent(TreeNode *root, unordered_map<TreeNode *, TreeNode * > &parent_node) {
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left) {
                parent_node[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                parent_node[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, TreeNode *> parent_node;
        make_parent(root, parent_node);
        queue<TreeNode *> q;
        unordered_map<TreeNode *, bool> vis;
        q.push(target);
        vis[target] = true;
        int level = 0;
        while(!q.empty()) {
            if(level == k) break;
            level++;
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++) {
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left && vis.find(curr->left) == vis.end()) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && vis.find(curr->right) == vis.end()) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent_node[curr] && vis.find(parent_node[curr]) == vis.end()) {
                    q.push(parent_node[curr]);
                    vis[parent_node[curr]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};