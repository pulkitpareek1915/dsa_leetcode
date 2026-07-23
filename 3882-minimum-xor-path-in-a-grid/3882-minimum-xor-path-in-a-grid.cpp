class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>& grid,int currxor,int &ans,vector<vector<vector<bool>>> &vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m)
        {
            return ;
        }
        currxor=currxor ^ grid[i][j];
        if(vis[i][j][currxor])
        {
            return ;
        }
        vis[i][j][currxor]=true;
        if(i==n-1 && j==m-1)
        {
            ans=min(ans,currxor);
            return ;
        }
        dfs(i,j+1,grid,currxor,ans,vis);
        dfs(i+1,j,grid,currxor,ans,vis);
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MAX;
        vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m, vector<bool>(1024, false)));
        dfs(0,0,grid,0,ans,vis);
        return ans;
    }
};