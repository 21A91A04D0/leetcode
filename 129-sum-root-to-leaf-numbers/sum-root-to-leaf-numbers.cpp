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
    int ans = 0;
    void fun(TreeNode* root, int temp) {
        if(root == nullptr) return;
        temp = temp * 10 + root->val;
        if(root->left == NULL and root->right == NULL) {
            // temp = temp * 10 + root->val;
            ans += temp;
            return;
        }
        
        
        fun(root->left, temp);
        fun(root->right, temp);
    }
    int sumNumbers(TreeNode* root) {
        fun(root, 0);
        return ans;
    }
};