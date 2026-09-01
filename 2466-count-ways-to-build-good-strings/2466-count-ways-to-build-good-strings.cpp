class Solution {
public:
    const int mod=1e9+7;
    int solve(int index,int zero,int one,vector<int> &dp)
    {
        
        if(index==0)
        {
            return 1;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int zerotake=0;
        if(index>=zero)
        {
            zerotake=solve(index-zero,zero,one,dp);
        }
        int onetake=0;
        if(index>=one)
        {
            onetake=solve(index-one,zero,one,dp);
        }
        return dp[index]=(zerotake+onetake)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0;
        vector<int> dp(high+1,-1);
        for(int i=low;i<=high;i++)
        {
            int m=high-low+1;
            
            ans=(ans+solve(i,zero,one,dp))%mod;
        }
        return ans;
    }
};