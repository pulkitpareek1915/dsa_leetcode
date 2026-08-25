class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        int i=1;
        int k1=k;
        int ans=0;
        while(1)
        {
            if(st.find(k)!=st.end())
            {
                i++;
                k=k1*i;
            }
            else{
                ans=k;
                break;
            }
        }
        return ans;
    }
};