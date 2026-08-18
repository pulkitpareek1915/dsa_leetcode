class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=1;
        int target=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]==target)
            {
                count++;
            }
        }
  
        return count < nums.size() ? 1 : 0;
    }
};