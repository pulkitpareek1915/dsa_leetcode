class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int left=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                left=i;
                break;
            }
        }
        if(left==-1) return ;
        for(int right=left+1;right<n;right++)
        {
            if(nums[right]!=0)
            {
                swap(nums[right],nums[left]);
                left++;
            }
        }
    }
};