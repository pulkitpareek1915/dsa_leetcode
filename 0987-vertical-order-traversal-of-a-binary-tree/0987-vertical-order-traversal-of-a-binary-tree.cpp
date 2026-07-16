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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>> mpp;
        vector<vector<int>> ans;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front().first;
                int vertical=q.front().second.first;
                int level=q.front().second.second;
                q.pop();
                if(node->left!=NULL)
                {
                    q.push({node->left,{vertical-1,level+1}});
                }
                if(node->right!=NULL)
                {
                    q.push({node->right,{vertical+1,level+1}});
                }
                mpp[vertical][level].insert(node->val); 
            }
        }
        for (auto &p : mpp) 
        {
            vector<int> col;
            for(auto &q:p.second)
            {
                for(int val:q.second)
                {
                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};