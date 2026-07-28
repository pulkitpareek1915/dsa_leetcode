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
    int ans=0;
    void maxzig(TreeNode* root,int direction,int len)
    {
        if(root==NULL)
        {
            return ;
        }
        ans=max(ans,len);
        if(direction==0)
        {
            maxzig(root->right,1,len+1);
            maxzig(root->left,0,1);
        }
        else{
            maxzig(root->left,0,len+1);
            maxzig(root->right,1,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        maxzig(root->left,0,1);
        maxzig(root->right,1,1);
        return ans;
    }
};