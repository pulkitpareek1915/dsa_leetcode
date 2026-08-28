class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int index,int target,vector<vector<int>>& types,vector<vector<int>> &dp)
    {
        if(index<0)
        {
            return (target==0);
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        long long ways=0;
        for(int k=0;k<=types[index][0];k++)
        {
            int points=k*types[index][1];
            if(target>=points)
            {
                ways+=solve(index-1,target-points,types,dp);
            }
        }
        return dp[index][target]=ways%MOD;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,types,dp);
    }
};