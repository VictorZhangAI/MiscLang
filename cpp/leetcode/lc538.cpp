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
    void createInorder(TreeNode* root, vector<int>& inorder)
    {
        if(!root)
        {
            return;
        }
        createInorder(root->left, inorder);
        inorder.push_back(root->val);
        createInorder(root->right, inorder);
    }
    void createTree(TreeNode* root, vector<int>& inorder, int& index)
    {
        if(!root)
            return;
        createTree(root->left, inorder, index);
        root->val = inorder[index++];
        createTree(root->right, inorder, index);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int> inorder;
        createInorder(root, inorder);

        for(int i = inorder.size() - 2; i >= 0; i--)
        {
            inorder[i] += inorder[i + 1];
        }
        int index = 0;
        createTree(root, inorder, index);

        return root;
    }
};
