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
        if(root == NULL)
            return "";
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr)
            {
                str += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
            else
            {
                str += "null,";
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
        {
            return NULL;
        }
        stringstream str(data);
        string s;
        getline(str, s, ',');
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            getline(str, s, ',');
            if(s == "null")
            {
                curr->left = NULL;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(s));
                curr->left = leftNode;
                q.push(leftNode);
            }
            getline(str, s, ',');
            if(s == "null")
            {
                curr->right = NULL;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(s));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
