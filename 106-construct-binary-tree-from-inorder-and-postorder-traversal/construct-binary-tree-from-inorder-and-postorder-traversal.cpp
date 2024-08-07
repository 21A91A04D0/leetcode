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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for(int i = 0 ; i < inorder.size() ; i++) {
            inMap[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1,postorder, 0, postorder.size() - 1, inMap);
    }

    TreeNode *build(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, unordered_map<int, int> &inMap){
        if(inStart > inEnd || postStart > postEnd) {
            return NULL;
        }

        int inRoot = inMap[postorder[postEnd]];
        int numsLeft = inRoot - inStart;
        TreeNode * root = new TreeNode(postorder[postEnd]);
        root->left = build(inorder, inStart, inRoot - 1, postorder, postStart,postStart + numsLeft - 1, inMap);
        root->right = build(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);
        return root;
    }
};