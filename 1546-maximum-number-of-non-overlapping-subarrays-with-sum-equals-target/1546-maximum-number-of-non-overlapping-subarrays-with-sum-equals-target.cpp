class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
         int prefixsum=0;
         int n=nums.size();
         int cnt=0;
         for(int i=0;i<nums.size();i++)
         {
            prefixsum=prefixsum+nums[i];
            int k=prefixsum-target;
            
            if(mpp.find(k)!=mpp.end())
            {
                cnt++;
                mpp.clear();
                mpp[0]=1;
                prefixsum = 0;
            }
            else{
                mpp[prefixsum]=1;
            }
         }
         return cnt;
    }
};