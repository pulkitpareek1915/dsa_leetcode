class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        int cnt=0;
        for(int i:nums)
        {
            if(i==0)
            {
                cnt++;
            }
            x=x^i;
        }
        if(cnt==n) return 0;
        if(x==0)
        {
            return n-1;
        }
        else{
            return n;
        }
    }
};