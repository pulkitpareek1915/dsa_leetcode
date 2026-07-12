class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        if(n==1) return {nums[0]};
       int ele1 = 0, ele2 = 0;
        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && ele2!=nums[i])
            {
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && ele1!=nums[i])
            {
                cnt2=1;
                ele2=nums[i];
            }
            else if(ele1==nums[i]){
                cnt1++;
            }
            else if(ele2==nums[i]){
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        int cnt3=0;
        int cnt4=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele1)
            {
                cnt3++;
            }
            else if(nums[i]==ele2){
                cnt4++;
            }
        }
        vector<int> ans;
        int num=n/3;
        if(cnt3>num){
            ans.push_back(ele1);
        }
        if(cnt4>num){
            ans.push_back(ele2);
        }
    return ans;
    }
};