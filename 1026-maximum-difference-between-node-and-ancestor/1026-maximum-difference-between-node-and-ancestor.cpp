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
    int diff=0;
    void solve(TreeNode* root,int minval,int maxval)
    {
        if(root==NULL) return ;
        diff=max(diff,max(abs(minval-root->val),abs(maxval-root->val)));
        minval=min(minval,root->val);
        maxval=max(maxval,root->val);
        solve(root->left, minval, maxval);
        solve(root->right, minval, maxval);
    }
    int maxAncestorDiff(TreeNode* root) {
        int minval=root->val;
        int maxval=root->val;
        solve(root,minval,maxval);
        return diff;
    }
};