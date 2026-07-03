class Solution {
public:
    long long power(long long a, int k, long long limit)
    {
        if(a == 0)
            return 0;

        long long ans = 1;

        while(k--)
        {
            if(ans > limit / a)
                return limit + 1;

            ans *= a;
        }

        return ans;
    }

    long long kthRoot(long long n, int k)
    {
        if(n < 0)
            return -1;

        long long start = 0;
        long long end = n;
        long long ans = 0;

        while(start <= end)
        {
            long long mid = start + (end - start) / 2;

            if(power(mid, k, n) <= n)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return ans;
    }

    int countKthRoots(int l, int r, int k)
    {
        long long ans = kthRoot(r, k);

        if(l > 0)
            ans -= kthRoot((long long)l - 1, k);
        else
            ans++;   

        return (int)ans;
    }
};