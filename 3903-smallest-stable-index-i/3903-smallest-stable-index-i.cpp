class Solution {
public:
    int maxi(vector<int>& nums,int n,int index)
    {
        int m=INT_MIN;
        for(int i=0;i<=index;i++)
            {
                m=max(m,nums[i]);
            }
        return m;
    }
    int mini(vector<int>& nums,int n,int index)
    {
        int m=INT_MAX;
        for(int i=index;i<n;i++)
            {
                m=min(m,nums[i]);
            }
        return m;
    }
    int firstStableIndex(vector<int>& nums, int k) {
     int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
            {
               int ans=maxi(nums,n,i)-mini(nums,n,i);
                if(ans<=k)
                {
                    return i;
                }
            }
        return -1;
    }
};