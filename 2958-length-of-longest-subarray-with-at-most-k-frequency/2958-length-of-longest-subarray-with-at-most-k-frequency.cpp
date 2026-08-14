class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0;
        int ans=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++)
        {
            map[nums[i]]++;
            while(j<i && map[nums[i]]>k)
            {
                map[nums[j]]--;
                if(map[nums[j]]==0)
                {
                    map.erase(nums[j]);
                }
                j++;
            }
            if(map[nums[i]]<=k)
            {
                ans=max(ans,i-j+1);
            }
        }
        return ans;
    }
};