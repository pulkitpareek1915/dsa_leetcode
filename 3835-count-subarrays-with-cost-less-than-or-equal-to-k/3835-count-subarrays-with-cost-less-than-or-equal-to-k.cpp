class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        int left=0;
        int right=0;
        long long ans = 0;
        multiset<int> st;
        while(right<n)
        {
            st.insert(nums[right]);
            while(left<=right && (1LL*(*st.rbegin()-*st.begin())*(right-left+1))>k)
            {
                st.erase(st.find(nums[left]));
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
    }
};