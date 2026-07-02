class Solution {
public:
        long long count(int a, int b, int c, long long mid)
{
    long long ab = lcm(1LL * a, 1LL * b);
    long long ac = lcm(1LL * a, 1LL * c);
    long long bc = lcm(1LL * b, 1LL * c);
    long long abc = lcm(ab, 1LL * c);

    return mid / a + mid / b + mid / c
         - mid / ab - mid / ac - mid / bc
         + mid / abc;
}

    int nthUglyNumber(int n, int a, int b, int c) {
        long long start = 1;
        long long end = 1LL * min({a, b, c}) * n;

        while(start <= end)
        {
            long long mid = start + (end - start) / 2;

            if(count(a, b, c, mid) < n)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return start;
    }
};