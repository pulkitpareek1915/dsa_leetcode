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
    
     int cnt=0;
    void maxi(TreeNode* root,int m)
    {
        if(root==NULL) return ;
        if(m<=root->val)
        {
            cnt++;
            m=root->val;
        }
        
            maxi(root->left,m);
            maxi(root->right,m);
        
        
    }
    int goodNodes(TreeNode* root) {
        maxi(root,INT_MIN);
        return cnt;
    }
};