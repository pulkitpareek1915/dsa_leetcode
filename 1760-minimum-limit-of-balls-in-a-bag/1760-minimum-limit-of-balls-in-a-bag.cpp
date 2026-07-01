class Solution {
public:
    long long ops(vector<int>& nums,int mid)
    {
        long long cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mid)
            {
              cnt+=ceil(double(nums[i])/mid)-1;
            }
        }
        return cnt;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        long long  start=1;
        long long  end=*max_element(nums.begin(),nums.end());
        long long  mid=start+(end-start)/2;
        while(start<=end)
        {
            if(ops(nums,mid)<=maxOperations)
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