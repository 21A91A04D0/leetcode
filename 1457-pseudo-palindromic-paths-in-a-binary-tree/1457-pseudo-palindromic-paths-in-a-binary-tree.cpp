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
    int cnt = 0;
    void fun(TreeNode* root, vector<int> freq) {
        if(root == NULL) return;
        freq[root->val]++;
        if(root->left == NULL and root->right == NULL) {
            int odd = 0;
            int even = 0;
            for(int i = 1 ; i < 11 ; i++) {
                if (freq[i] % 2 == 0) even++;
                else odd++;
            }
            if(odd > 1) return;
            else cnt++;
        }
        fun(root->left, freq);
        fun(root->right, freq);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> f(11,0);
        fun(root,f);
        return cnt;
    }
};