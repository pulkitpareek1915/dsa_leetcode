class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int ps=0;
         unordered_map<int,int>map;
         map[0] = 1;
         int ans=0;
         int rem=0;
         for(int i=0;i<n;i++)
         {
            ps+=nums[i];
            rem=ps%k;
            if(rem<0)
            {
                rem=rem+k;
            }
            if(map.count(rem))
            {
                ans+=map[rem];
                map[rem]++;
            }
            else{
                map[rem]=1;
            }
         }
    return ans;
    }
};