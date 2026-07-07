class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long sum=0;
        string ans="";
        int cnt=0;
        int m=s.size();
        for(int i=0;i<m;i++)
        {
           if (s[i] != '0')
            {
                ans+=s[i];
                cnt=1;
                sum+=s[i]-'0';
            }
        }
        if(cnt==0) return 0;
        long long num=stoi(ans);
        
        return 1LL*num*sum;
    }
};