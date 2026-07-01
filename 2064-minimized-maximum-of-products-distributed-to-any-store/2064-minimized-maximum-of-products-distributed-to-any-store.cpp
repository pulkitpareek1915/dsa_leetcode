class Solution {
public:
    int disrtribute( vector<int>& quantities,int mid)
    {
        int cnt=0;
        for(int i=0;i<quantities.size();i++)
        {
            if(quantities[i]>=mid)
            {
                cnt+=ceil(double(quantities[i])/mid);
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start=1;
        int end=*max_element(quantities.begin(),quantities.end());
        int mid=start+(end-start)/2;
        sort(quantities.begin(),quantities.end());
        while(start<=end)
        {
            if(disrtribute(quantities,mid)<=n)
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