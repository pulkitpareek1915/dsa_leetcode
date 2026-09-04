class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<char,pair<int,int>>> q;
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') {
                q.push({'O',{i,0}});
                vis[i][0] = 1;
            }
            if(board[i][m-1] == 'O') {
                q.push({'O',{i,m-1}});
                vis[i][m-1] = 1;
            }
        }

        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O' && !vis[0][j]) {
                q.push({'O',{0,j}});
                vis[0][j] = 1;
            }
            if(board[n-1][j] == 'O' && !vis[n-1][j]) {
                q.push({'O',{n-1,j}});
                vis[n-1][j] = 1;
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            char node=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=delrow[i]+row;
                int nc=delcol[i]+col;
                if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && board[nr][nc]=='O')
                {
                    vis[nr][nc]=1;
                    q.push({'O',{nr,nc}});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};