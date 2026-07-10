class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> map;
        int n=changed.size();
        if(n%2==1) return {};
        
        sort(changed.begin(),changed.end());
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
           map[changed[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            int lowest=changed[i];
            if(map[lowest]==0) continue;
            if(map[2*lowest]==0) return {};
            ans.push_back(lowest);
            map[lowest]--;
            map[2*lowest]--;
        }
        if(ans.size()!=n/2) return {};
        return ans;
    }
};