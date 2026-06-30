class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        int start=0;
        int end=n-1;
        int mid=start+(end-start)/2;
        while(start < end)
        {
            if(mid-1>=0 && mid+1<=n-1)
            {
                if(nums[mid]<nums[mid+1] && nums[mid]>nums[mid-1])
                {
                    return nums[mid];
                }
                if((nums[mid]==nums[mid-1] && mid%2==0 )|| (nums[mid]==nums[mid+1] && mid%2==1))
                {
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
                mid=start+(end-start)/2;
            }
            else{
                 if(mid==0)
                {
                    return nums[0];
                }
                else
                {
                    return nums[n-1];
                }
            }
        }
           int ans=nums[mid];
            return ans;
    }
};