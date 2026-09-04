class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> mat(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1)
                {
                    mat[i][j]=0;
                }
            }
        }
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0 && !vis[i][j])
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=delrow[i]+row;
                int nc=delcol[i]+col;
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc]==-1)
                {
                    vis[nr][nc]=1;
                    q.push({{nr,nc},steps+1});
                    mat[nr][nc]=steps+1;
                }
            }
        }
        return mat;
    }
};