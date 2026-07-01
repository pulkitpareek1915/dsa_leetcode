class Solution {
public:
    long long count(long long mid, long long a, long long b)
    {
        long long cnt =  mid/a + mid/b - mid/lcm(a,b);
        return cnt;
    }

    int nthMagicalNumber(int n, int a, int b) {
        const int mod = 1000000007;

        long long start = 2;
        long long end =  1LL * min(a, b) * n;

        while(start <= end)
        {
            long long mid = start + (end - start) / 2;

            long long c = count(mid, a, b);

            if(c < n)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return start % mod;
    }
};