class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(2*n,0);
        int sum=0;
        int sum1=0;
        int ts=0;
        int maxi=nums[0];
        int mini=nums[0];
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0)
            {
                sum=0;
            }
            
            sum1+=nums[i];
            mini=min(sum1,mini);
            if(sum1>0)
            {
                sum1=0;
            }
            
            ts+=nums[i];
        }
        if (ts == mini) {
            return maxi;
        }
        return max(maxi,ts-mini);
    }
};