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
    map<pair<TreeNode *, bool>, int> mp;
    int help(TreeNode *root, bool take) {
        if(!root) return 0;
        int l = INT_MIN, r = INT_MIN;
        if(mp.count({root, take})) return mp[{root, take}];
        int ans = 0;
        if(take) {
            l = help(root->left, !take);
            r = help(root->right, !take);
            ans = root->val;
        }
        int nl = help(root->left, true);
        int nr = help(root->right, true);
        return mp[{root, take}] = max((l*1ll + r + ans)*1ll, (nl + nr)*1ll);
    }
    int rob(TreeNode* root) {
        return help(root, true);
    }
};