class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1,0);
        int m=bookings.size();
        for(int i=0;i<m;i++)
        {
            int left=bookings[i][0]-1;
            int right=bookings[i][1]-1;
            int seat=bookings[i][2];
            diff[left]+=seat;
            if(right+1<n)
            {
                diff[right+1]-=seat;
            }
        }
        for(int i=1;i<=n;i++)
            {
                diff[i]+=diff[i-1];
            }
            diff.pop_back();
        return diff;
    }
};