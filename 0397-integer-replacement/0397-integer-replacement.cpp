class Solution {
public:
    int integerReplacement(int n) {
        long long m=n;
        int cnt=0;
        while(m>1)
        {
            if(m==3) m--;
            else if(m%2==0) m=m/2;
            else if(m%4==3) m++;
            else m--;
            cnt++;
        }
        return cnt;
    }
};