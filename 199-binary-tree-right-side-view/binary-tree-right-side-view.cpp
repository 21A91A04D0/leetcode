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
    void fun(TreeNode *root, vector<int> &ds, int cnt) {
        if(!root) return;
        if(ds.size() == cnt) {
            ds.push_back(root->val);
        }
        fun(root->right, ds, cnt + 1);
        fun(root->left, ds, cnt + 1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ds;
        fun(root, ds, 0);
        return ds;
    }
};