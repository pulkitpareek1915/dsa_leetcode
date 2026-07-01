class Solution {
public:
    bool cancollect(vector<int>& price,int mid, int k)
    {
        int cnt=1;
        int lastpos=price[0];
        for(int i=1;i<price.size();i++)
        {
            if((price[i]-lastpos)>=mid)
            {
                cnt++;
                lastpos=price[i];
            }
        }
        if(cnt>=k)
        {
            return true;
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        sort(price.begin(),price.end());
        int start=1;
        int end=price[n-1]-price[0];
        int mid=start+(end-start)/2;
        while(start<=end)
        {
            if(cancollect(price,mid,k)==true)
            {
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return end;
    }
};