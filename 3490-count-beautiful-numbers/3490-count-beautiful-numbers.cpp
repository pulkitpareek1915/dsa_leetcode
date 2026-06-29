class Solution {
public:
    long long dp[11][2][2][91][91];

    long long solve(string &s,int idx,int tight,int lz,
                    int sum,int rem,int target)
    {
        if(idx==s.size())
        {
            return (!lz && sum==target && rem==0);
        }

        if(dp[idx][tight][lz][sum][rem]!=-1)
            return dp[idx][tight][lz][sum][rem];

        int ub=tight ? s[idx]-'0' : 9;

        long long ans=0;

        for(int dig=0;dig<=ub;dig++)
        {
            int ntight=tight && (dig==ub);

            if(lz && dig==0)
            {
                ans+=solve(s,idx+1,ntight,1,0,1%target,target);
            }
            else
            {
                int nsum=sum+dig;

                if(nsum>target) continue;

                int nrem;

                if(lz)
                    nrem=dig%target;
                else
                    nrem=(rem*dig)%target;

                ans+=solve(s,idx+1,ntight,0,nsum,nrem,target);
            }
        }

        return dp[idx][tight][lz][sum][rem]=ans;
    }

    long long f(long long x)
    {
        if(x<=0) return 0;

        string s=to_string(x);

        long long ans=0;

        for(int target=1;target<=9*s.size();target++)
        {
            memset(dp,-1,sizeof(dp));
            ans+=solve(s,0,1,1,0,1%target,target);
        }

        return ans;
    }

    int beautifulNumbers(int l, int r) {
        return f(r)-f(l-1);
    }
};