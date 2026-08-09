class Solution {
public:
    long long numOfSubsequences(string s) {
        int n=s.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L') cnt++;
            prefix[i]=cnt;
        }
        cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='T') cnt++;
            suffix[i]=cnt;
        }
        long long op1=0;
        long long  op2=0;
        long long op3=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='C')
            {
                op1+=(prefix[i]+1)*suffix[i];
                op2+=prefix[i]*(suffix[i]+1);
                ans+=prefix[i]*suffix[i];
            }
            else{
                op3 = max(op3, (long long)prefix[i] * suffix[i]);
            }
        }
        return max({op1,op2,op3+ans});
    }
};