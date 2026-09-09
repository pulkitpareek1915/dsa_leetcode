class Solution {
public:
     int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
     {
        int n=matrix.size();
        int m=matrix[0].size();
        if(i<0 || j<0 || j>=m){
            return 1e9;
        }
        if(i==n-1)
        {
            return matrix[n-1][j];
        }
        
        if(dp[i][j]!=INT_MAX)
        {
            return dp[i][j];
        }
        int bottom=matrix[i][j]+solve(i+1,j,matrix,dp);
        int right=matrix[i][j]+solve(i+1,j+1,matrix,dp);
        int left=matrix[i][j]+solve(i+1,j-1,matrix,dp);
        return dp[i][j]=min({bottom,right,left});
     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        int ans=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,solve(0,i,matrix,dp));
        }
        return ans;
    }
};