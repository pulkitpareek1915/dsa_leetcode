class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> map;
        int n=nums.size();
        int count=0;
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                map[nums[i]]++;
            
            int freq=map[nums[i]];
            if(count<freq)
            {
                ans=nums[i];
            }
            if(count==freq)
            {
                ans=min(nums[i],ans);
            }
            count=max(count,freq);
            }
        }
        if(ans==INT_MAX) return -1;
    return ans;
    }
};