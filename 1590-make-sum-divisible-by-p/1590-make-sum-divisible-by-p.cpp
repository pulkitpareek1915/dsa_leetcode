class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long ts=0;
        long long target=0;
        int n=nums.size();
        unordered_map<long long,int> map;
        map[0]=-1;
        for(int i=0;i<n;i++)
        {
            ts+=nums[i];
        }
        target=ts%p;
        int minlen=n;
        long long cs=0;
        if(target==0) return 0;
        for(int i=0;i<n;i++)
        {
            cs=(cs+nums[i])%p;
            int need=(cs-target+p)%p;
            if(map.count(need))
            {
                minlen=min(minlen,i-map[need]);
            }
            map[cs]=i;
        }
        return minlen==n ?-1 :minlen;
    }
};