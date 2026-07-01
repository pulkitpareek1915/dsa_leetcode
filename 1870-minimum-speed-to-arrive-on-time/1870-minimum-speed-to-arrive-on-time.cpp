class Solution {
public:
    
    double time(vector<int>& dist, long long mid)
    {
        double time=0;
        int n=dist.size();
        for(int i=0;i<n-1;i++)
        {
            time+=ceil(double(dist[i])/mid);
        }
        return time + double(dist[n-1])/mid;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start=1;
        long long end=10000000;
        int n=dist.size();
        long long mid=start+(end-start)/2;
        if(n>ceil(hour)) return -1;
        while(start<=end)
        {
            if(time(dist,mid)<=hour)
            {
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return start;
    }
};