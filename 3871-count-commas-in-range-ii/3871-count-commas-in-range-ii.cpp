class Solution {
public:
    long long countCommas(long long n) {
        
        
        long long ans=0;
        long long start=1000;
        int coma=1;
        while(start<=n){
            long long end=1000*start-1;
            long long num=min(end,n)-start+1;
            ans=ans+num*coma;
            coma++;
            start=start*1000;
        }
        return ans;
    }
};