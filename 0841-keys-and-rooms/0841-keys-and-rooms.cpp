class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        int m=rooms[0].size();
        
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int room=q.front();
            q.pop();
            for(auto it:rooms[room])
            {
                if(!vis[it])
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
            cout<<vis[i]<<" ";
        }
        if(cnt==n) return true;
        return false;
    }
};