class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
            return;
        }

        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> ans1, ans2;

        dfs(root1, ans1);
        dfs(root2, ans2);

        return ans1 == ans2;
    }
};