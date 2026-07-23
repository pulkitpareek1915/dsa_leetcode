class EventManager {
public:
    priority_queue<pair<int,int>> q;
    unordered_map<int,int> mp;
    EventManager(vector<vector<int>>& events) {
        
        int n=events.size();
        int m=events[0].size();
        for(int i=0;i<n;i++)
            {
                mp[events[i][0]]=events[i][1];
                q.push({events[i][1],-events[i][0]});
            }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId]=newPriority;
        q.push({newPriority,-eventId});
    }
    
    int pollHighest() {
        while(!q.empty())
            {
                auto top=q.top();
                q.pop();
                int pr=top.first;
                int id=-top.second;
                
            
        if(mp.count(id) && mp[id]==pr)
        {
            mp.erase(id);
            return id;
        }
            }
        return -1;
    }
};
