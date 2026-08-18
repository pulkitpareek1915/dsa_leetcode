class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n+1);
        int i2,i3,i5;
        i2=1;
        i3=1;
        i5=1;
        ugly[1]=1;
        for(int i=2;i<=n;i++)
        {
            int i2uglynum=ugly[i2]*2;
            int i3uglynum=ugly[i3]*3;
            int i5uglynum=ugly[i5]*5;
            ugly[i]=min({i2uglynum,i3uglynum,i5uglynum});
            if(ugly[i]==i2uglynum)
            {
                i2++;
            }
            if(ugly[i]==i3uglynum)
            {
                i3++;
            }
            if(ugly[i]==i5uglynum)
            {
                i5++;
            }
        }
        return ugly[n];
    }
};