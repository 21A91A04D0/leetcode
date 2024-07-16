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
int maxheight(TreeNode* root, int &mx) {
    if(root == nullptr) return 0;
    int lh = maxheight(root->left, mx);
    int rh = maxheight(root->right, mx);
    mx = max(mx, lh + rh);
    return 1 + max(lh, rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = INT_MIN;
        int a = maxheight(root, mx);
        return mx;
    }
};