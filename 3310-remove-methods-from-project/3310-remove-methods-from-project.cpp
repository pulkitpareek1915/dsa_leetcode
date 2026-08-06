class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int m=invocations.size();
        vector<vector<int>> adjls(n);
        for(auto &it:invocations)
        {
            int u=it[0];
            int v=it[1];
            adjls[u].push_back(v);
           
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(k);
        vis[k]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int neighbour:adjls[node])
            {
                if(!vis[neighbour])
                {
                    vis[neighbour]=1;
                    q.push(neighbour);
                }
            }
        }
         for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};