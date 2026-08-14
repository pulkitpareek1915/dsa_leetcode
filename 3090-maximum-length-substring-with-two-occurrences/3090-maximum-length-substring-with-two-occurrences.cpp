class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int j=0;
        int ans=0;
        unordered_map<char,int> map;
        for(int i=0;i<n;i++)
        {
            map[s[i]]++;
            while(j<i && map[s[i]]>2)
            {
                map[s[j]]--;
                if(map[s[j]]==0)
                {
                    map.erase(s[j]);
                }
                j++;
            }
            if(map[s[i]]<=2)
            {
                ans=max(ans,i-j+1);
            }
        }
        return ans;
    }
};