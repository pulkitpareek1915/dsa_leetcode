class Solution {
public:
    long long count(vector<int>& candies,int mid)
    {
        long long cnt=0;
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]>=mid)
            {
                cnt+=abs(candies[i]/mid);
            }
        }
        return cnt;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int start=1;
        int end=*max_element(candies.begin(),candies.end());
        int mid=start+(end-start)/2;
        sort(candies.begin(),candies.end());
        while(start<=end)
        {
            if(count(candies,mid)<k)
            {
                end=mid-1;
                
            }
            else{
                start=mid+1;
            }
         mid=start+(end-start)/2;
        }
        return end;
    }
};