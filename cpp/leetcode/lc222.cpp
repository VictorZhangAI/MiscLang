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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        TreeNode* left = root;
        TreeNode* right = root;
        int heightL = 0;
        int heightR = 0;
        while(left != NULL)
        {
            heightL++;
            left = left->left;
        }
        while(right != NULL)
        {
            heightR++;
            right = right->right;
        }
        if(heightL == heightR)
            return pow(2, heightL) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
