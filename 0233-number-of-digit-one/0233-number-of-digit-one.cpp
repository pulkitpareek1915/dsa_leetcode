class Solution {
public:
    int solve(string &s,int index,int tight,int count,int size,vector<vector<vector<int>>> &dp)
    {
        if(index==size)
        {
            return count;
        }
        if(dp[index][tight][count]!=-1)
        {
            return dp[index][tight][count];
        }
        int lb=0;
        int up=(tight==1) ?   s[index]-'0' :9;
        int ans=0;
        for(int digit=lb;digit<=up;digit++)
        {
            int updatedcnt=count+((digit==1) ? 1:0);
            ans+=solve(s,index+1,(tight && digit==up),updatedcnt,size,dp);
        }
        return dp[index][tight][count]=ans;
    }
    int countDigitOne(int n) {
        string s=to_string(n);
        int size=s.size();
        vector<vector<vector<int>>> dp(size,vector<vector<int>>(2,vector<int>(11,-1)));
        return solve(s,0,1,0,size,dp); 
    }
};