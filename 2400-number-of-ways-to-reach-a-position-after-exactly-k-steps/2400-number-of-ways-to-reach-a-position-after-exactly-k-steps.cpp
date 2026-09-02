class Solution {
public:
    const int mod=1e9+7;
    int solve(int index,int steps,int startPos,int endPos,vector<vector<int>> &dp)
    {
        if(steps==0)
        {
            return (index==startPos);
        }
        if(dp[index+1000][steps]!=-1)
        {
            return dp[index+1000][steps];
        }
        
        long long  left  =solve(index-1,steps-1,startPos,endPos,dp);
        long long right=solve(index+1,steps-1,startPos,endPos,dp);
        
        return dp[index+1000][steps]=(left+right)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3001,vector<int>(k+1,-1));
        return solve(endPos,k,startPos,endPos,dp);
    }
};