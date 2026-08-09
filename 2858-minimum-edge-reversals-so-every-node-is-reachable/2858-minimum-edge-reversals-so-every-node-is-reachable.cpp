class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
         for(auto it:edges)
         {
            int u=it[0];
            int v=it[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
         }
         vector<int> ans(n,0);
         vector<int> vis(n,0);
         queue<int> q;
         q.push(0);
         vis[0]=1;
         int cnt=0;
         while(!q.empty())
         {
            int node=q.front();
            q.pop();
            for(auto &[nigh,cost]:adj[node])
            {
                if(vis[nigh]) continue;

                vis[nigh]=1;
                cnt+=cost;
                q.push(nigh);
            }
         }
         ans[0]=cnt;
         for(int i=0;i<n;i++)
         {
            vis[i]=0;
         }
         q.push(0);
         vis[0]=1;
         while(!q.empty())
         {
            int node=q.front();
            q.pop();
            for(auto &[nigh,cost]:adj[node])
            {
                if(vis[nigh]) continue;
                if(cost==0)
                {
                    ans[nigh]=ans[node]+1;
                }
                else{
                    ans[nigh]=ans[node]-1;
                }
                vis[nigh]=1;
                q.push(nigh);
            }
         }
         return ans;
    }
};