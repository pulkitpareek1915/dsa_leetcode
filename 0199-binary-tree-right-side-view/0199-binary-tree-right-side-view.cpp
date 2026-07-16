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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        vector<int> ans;
        if(root==NULL) return {};
        q.push({root,0});
        map<int,int> map;
        while(!q.empty())
        {
            TreeNode* node=q.front().first;
            int level=q.front().second;
            q.pop();
            if(node->right!=NULL)
            {
                q.push({node->right,level+1});
            }
            if(node->left!=NULL)
            {
                q.push({node->left,level+1});
            }
            if(map.find(level)==map.end())
            {
                map[level]=node->val;
            }
        }
        for(auto it:map)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};