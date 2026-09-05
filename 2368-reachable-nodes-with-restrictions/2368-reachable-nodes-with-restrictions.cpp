class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> vis(n,0);
        unordered_set<int> st(restricted.begin(),restricted.end());
        vector<vector<int>> adjls(n);
        for( auto it:edges)
        {
            adjls[it[0]].push_back(it[1]);
            adjls[it[1]].push_back(it[0]);
        }
        queue<int> q;
        if(st.find(0)==st.end())
        {
            vis[0]=1;
            q.push(0);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adjls[node])
            {
                if(!vis[it] && st.find(it)==st.end())
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==1)
            {
                cnt++;
            }
        }
        return cnt;
    }
};