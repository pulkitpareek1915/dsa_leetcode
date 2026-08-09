class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int target=0;
        unordered_map<int,int> map;
        int ans=0;
        for(int i=0;i<n;i++)
        {
           map[nums[i]]++;
        }
        for(auto it:map)
        {
            target=it.first+k;
            if(k==0)
            {
                if(it.second>1)
                {
                    ans++;
                }
            }
            else if(map.find(target)!=map.end())
            {
                ans++;
            }
        }
        return ans;
    }
};