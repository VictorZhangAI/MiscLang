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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        vector<TreeNode*> s;
        s.push_back(new TreeNode(preorder[0]));
        for(int i = 1, j = 0; i < preorder.size(); i++)
        {
            TreeNode* node = new TreeNode(preorder[i]);
            while(s.back()->val == postorder[j])
                s.pop_back(), j++;
            if(s.back()->left == NULL)
                s.back()->left = node;
            else
                s.back()->right = node;
            s.push_back(node);
        }
        return s[0];
    }
};
