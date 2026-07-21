class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int right=n-1;
        while(left<right)
        {
            if(nums[left]%2==1 && nums[right]%2==0)
            {
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
            else if(nums[right]%2==0)
            {
                left++;
            }
            else{
                right--;
            }
        }
        return nums;
    }
};