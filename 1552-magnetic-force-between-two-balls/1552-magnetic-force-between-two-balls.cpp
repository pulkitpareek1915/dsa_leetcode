class Solution {
public:
    bool canplace(vector<int>& position, int m,int mid)
    {
        int cnt=1;
       int lastdist=position[0];
       int n=position.size();
        for(int i=1;i<n;i++)
        {
            if((position[i]-lastdist)>=mid)
            {
                cnt++;
                lastdist=position[i];
            }
        }
        if(cnt>=m)
        {
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int start=1;
        int end=position[n-1]-position[0];
        int mid=start+(end-start)/2;
        while(start<=end)
        {
            if(canplace(position,m,mid)==true)
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