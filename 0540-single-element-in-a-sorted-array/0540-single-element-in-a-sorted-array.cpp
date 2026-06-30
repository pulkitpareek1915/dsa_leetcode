class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size()-1;
        int start=0;
        int end =n;
        int mid= mid=start+(end-start)/2;
        int ans=0;
       while(start<=end )
        {
            if(nums.size()==1)
            {
                return nums[0];
            }
            if(mid-1>=0 && mid+1 <=n)
            {
                if(nums[mid]<nums[mid+1] && nums[mid-1]<nums[mid])
                {
                    return nums[mid]; 
                }
                if((nums[mid]==nums[mid-1] && (mid)%2==0) || ((nums[mid]==nums[mid+1] && (mid)%2!=0)))
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
                 mid=start+(end-start)/2;
            }
            else
            {
                if(mid==0)
                {
                    return nums[0];
                }
                else
                {
                    return nums[n];
                }
            }
           
        }
        ans=nums[mid];
return ans;
    }
};