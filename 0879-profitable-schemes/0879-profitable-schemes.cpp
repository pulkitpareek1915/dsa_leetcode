class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int index,int target,int maxinum,vector<int>& group, vector<int>& profit,vector<vector<vector<int>>> &dp)
    {
        if(index<0)
        {
            return target==0;
        }
        if(dp[index][target][maxinum]!=-1)
        {
            return dp[index][target][maxinum];
        }
        int nottake=solve(index-1,target,maxinum,group,profit,dp);
        int take=0;
        if(group[index]<=maxinum)
        {
            take=solve(index-1,max(0,target-profit[index]),maxinum-group[index],group,profit,dp);
        }
        return dp[index][target][maxinum]=(take+nottake)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m=group.size();
        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                minProfit+1,
                vector<int>(n+1,-1)
            )
        );
        return solve(m-1,minProfit,n,group,profit,dp);
    }
};