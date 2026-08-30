class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int minindex=0;
        int maxindex=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maxi){
                maxindex=i;
            }
            if(nums[i]==mini){
                minindex=i;
            }
        }
        if(maxindex<minindex)
        {
            swap(maxindex,minindex);
        }
        int front=maxindex+1;
        int back=n-minindex;
        int both=(minindex+1)+(n-maxindex);
        return min({front,back,both});
    }
};