class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid,int delrow[],int delcol[], vector<vector<int>> &vis)
    {
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nr=delrow[i]+row;
            int nc=delcol[i]+col;
            if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1)
            {
                dfs(nr,nc,grid,delrow,delcol,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 && !vis[i][0])
            {
                dfs(i,0,grid,delrow,delcol,vis);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1])
            {
                dfs(i,m-1,grid,delrow,delcol,vis);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1 && !vis[0][j])
            {
                dfs(0,j,grid,delrow,delcol,vis);
            }
            if(grid[n-1][j]==1 && !vis[n-1][j])
            {
                dfs(n-1,j,grid,delrow,delcol,vis);
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};