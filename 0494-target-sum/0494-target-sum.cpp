class Solution {
public:
    int solve(int index,int tar,vector<vector<int>> &dp,vector<int>& nums)
    {
        if(index==0){
            if(tar==0 && nums[0]==0) return 2;
            if(tar==0 || tar==nums[0]) return 1;
            return 0;
        }
        if(dp[index][tar]!=-1){
            return dp[index][tar];
        }
        int nottake=solve(index-1,tar,dp,nums);
        int take=0;
        if(tar>=nums[index]){
            take=solve(index-1,tar-nums[index],dp,nums);
        }
        return dp[index][tar]=take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        if((sum-target)<0){
            return 0;
        }
        if((sum-target)%2==1){
            return 0;
        }
        int tar=(sum-target)/2;
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
        if(nums[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
        }
        if(nums[0]!=0 && nums[0]<=tar){
            dp[0][nums[0]]=1;
        }
     // Fill DP table
    for(int i = 1; i < n; i++) {
        for(int t = 0; t <= tar; t++) {

            int nottake = dp[i-1][t];

            int take = 0;
            if(nums[i] <= t)
                take = dp[i-1][t - nums[i]];

            dp[i][t] = take + nottake;
        }
    }

    return dp[n-1][tar];
    }
};