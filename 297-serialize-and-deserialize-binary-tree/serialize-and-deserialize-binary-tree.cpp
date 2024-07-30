/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";

        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()) {
            TreeNode * it = q.front();
            q.pop();
            if(it == NULL) s += "#,";
            else {
                s += to_string(it->val);
                s += ',';
            }
            if(it != NULL) {
                q.push(it->left);
                q.push(it->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* it = q.front();
            q.pop();

            getline(s,str,',');
            if(str == "#") {
                it->left = NULL;
            }
            else {
                TreeNode * nn = new TreeNode(stoi(str));
                it->left = nn;
                q.push(nn);
            }
            getline(s,str,',');
            if(str == "#") {
                it->right = NULL;
            }
            else {
                TreeNode * nn1 = new TreeNode(stoi(str));
                it->right = nn1;
                q.push(nn1);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));