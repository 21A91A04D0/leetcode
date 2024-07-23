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
    bool fun(TreeNode *root1, TreeNode *root2) {
        if(!root1 and !root2) return true;
        if(!root1 and root2 || root1 and !root2 || root1->val != root2->val) return false;
        int l = fun(root1->left, root2->right);
        int r = fun(root1->right, root2->left);
        if(l == false || r == false) return false;
        return l && r;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return false;
        return fun(root->left, root->right);
    }
};