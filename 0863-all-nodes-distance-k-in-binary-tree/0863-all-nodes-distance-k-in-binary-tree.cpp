/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root,map<TreeNode* ,TreeNode*> &parent_track)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=NULL)
            {
                q.push(node->left);
                parent_track[node->left]=node;
            }
            if(node->right!=NULL)
            {
                q.push(node->right);
                parent_track[node->right]=node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode* ,TreeNode*> parent_track;
        parent(root,parent_track);
        queue<TreeNode*> q;
        int curr_level=0;
        map<TreeNode*,bool> vis;
        q.push(target);
        vis[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            if(curr_level==k) break;
            curr_level++;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right!=NULL && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(parent_track[node] && !vis[parent_track[node]])
                {
                    q.push(parent_track[node]);
                    vis[parent_track[node]]=true;
                }
            }
        }
        vector<int> ans;
            while(!q.empty())
            {
                TreeNode* curr=q.front();
                ans.push_back(curr->val);
                q.pop();
            }
            return ans;
    }
};