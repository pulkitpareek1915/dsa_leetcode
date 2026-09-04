class Solution {
public:
    int dfs(int node,vector<vector<int>> &adjls,vector<int> &vis)
    {
        vis[node]=1;
        int ans=1;
        for(auto it:adjls[node])
        {
            if(!vis[it])
            {
                ans+=dfs(it,adjls,vis);
            }
        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adjls(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                long long dx=bombs[i][0]-bombs[j][0];
                long long  dy=bombs[i][1]-bombs[j][1];
                int radius=bombs[i][2];
                long long dist=dx*dx+dy*dy;
                if(dist<=1LL*radius*radius)
                {
                    adjls[i].push_back(j);
                }
            }
        }
        queue<int> q;
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,0);
            if(!vis[i])
            {
                maxi=max(maxi,dfs(i,adjls,vis));
            }
        }
        return maxi;
    }
};