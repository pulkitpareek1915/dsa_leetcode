class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans=INT_MAX;
        int a=INT_MAX;
        for(int i=0;i<nums.size();i++)
            {
                for(int j=0;j<nums.size();j++)
                    {
                        if(nums[i]==1 && nums[j]==2)
                        {
                            a=abs(i-j);
                        }
                        ans=min(ans,a);
                    }
            }
            if(ans==INT_MAX)
            {
                return -1;
            }
        return ans;
    }
};