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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root]=NULL;
        while(!q.empty())
        {
            int size=q.size();
            TreeNode* nx = NULL;
            TreeNode* ny = NULL;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->val == x) nx = node;
                if(node->val == y) ny = node;
                if(node->left!=NULL)
                {
                    parent[node->left]=node;
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    parent[node->right]=node;
                    q.push(node->right);
                }
               
            }
             if(nx && ny)
                return parent[nx] != parent[ny];
           
        }
        return false;
    }
};