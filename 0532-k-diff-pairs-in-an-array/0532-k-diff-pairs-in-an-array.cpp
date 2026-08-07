class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int right=1;
        long long diff=0;
        map<pair<int,int>, int> map;
        while(left <=right &&right<n)
        {
            diff=abs(nums[right]-nums[left]);
            if(diff==k)
            {
                if(left!=right)
                {
                    map[{nums[left],nums[right]}]=1;
                }
            }
            if(diff>k)
            {
                left++;
            }
            else {
                right++;
            }
        }
        return map.size();
    }
};