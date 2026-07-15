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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL) return {};
        int cnt=0;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
                
            }
            if(cnt%2==1)
            {
                reverse(level.begin(),level.end());
            }
            cnt++;
            ans.push_back(level);
        }
        return ans;
    }
};