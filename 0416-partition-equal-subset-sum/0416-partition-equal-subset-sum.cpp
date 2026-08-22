class Solution {
public:
    bool solve(int index,int target,vector<int> &nums,vector<vector<int>> &dp,int n)
    {
        if(target==0)
        {
            return true;
        }
        if(index==n-1)
        {
            return nums[n-1]==target;
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        bool take=false;
        if(nums[index]<=target)
        {
            take=solve(index+1,target-nums[index],nums,dp,n);
        }
        bool nottake=solve(index+1,target,nums,dp,n);
        return dp[index][target]=take || nottake;

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(0,target,nums,dp,n);
    }
};