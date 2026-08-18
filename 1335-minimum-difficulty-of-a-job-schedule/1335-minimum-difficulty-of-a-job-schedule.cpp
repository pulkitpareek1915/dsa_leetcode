class Solution {
public:
    int solve(int index,int d,vector<vector<int>>& dp,vector<int>& jobDifficulty,int n)
    {
        if(d==1)
        {
            int maxd=INT_MIN;
            for(int i=index;i<n;i++)
            {
                maxd=max(maxd,jobDifficulty[i]);
            }
            return maxd;
        }
        if(dp[index][d]!=-1) return dp[index][d];
        int maxd=jobDifficulty[index];
        int finalresult=INT_MAX;
        for(int i=index;i<=n-d;i++)
        {
            maxd=max(maxd,jobDifficulty[i]);
            int result=maxd+solve(i+1,d-1,dp,jobDifficulty,n);
            finalresult=min(finalresult,result);
        }
        return dp[index][d]=finalresult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        if(n<d) return -1;
        return solve(0,d,dp,jobDifficulty,n);
    }
};