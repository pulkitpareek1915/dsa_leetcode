class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        health -= grid[0][0];
        if (health < 1) return false;
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},health});
        vis[0][0]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int heal=q.front().second;
            q.pop();
            if(r==n-1 && c==m-1 && heal>=1) return true;
            for(int i=0;i<4;i++)
            {
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m  )
                {
                    int newhel=heal-grid[nr][nc];
                    if(newhel>=1 && newhel>vis[nr][nc])
                    {
                        vis[nr][nc]=newhel;
                        q.push({{nr,nc},newhel});
                    }
                }
            }
        }
        return false;
    }
};