class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnto=0;
        int cnt1=0;
        int cnt2=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0){
                cnto++;
            }
            else if(nums[i]==1){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        for(int i=0;i<cnto;i++)
        {
            nums[i]=0;
        }
        for(int i=cnto;i<cnto+cnt1;i++)
        {
            nums[i]=1;
        }
        for(int i=cnto+cnt1;i<n;i++)
        {
            nums[i]=2;
        }
    }
};