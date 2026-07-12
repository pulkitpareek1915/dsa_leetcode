class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(n+m,0);
        int left=0;
        int right=0;
        int index=0;
        while(left < m && right < n)
        {
            if(nums1[left]>nums2[right])
            {
                ans[index]=nums2[right];
                index++;
                right++;
            }
            else{
                ans[index]=nums1[left];
                index++;
                left++;
            }
        }
        while(left<m)
        {
            ans[index]=nums1[left];
            index++;
            left++;
        }
        while(right<n)
        {
            ans[index]=nums2[right];
            index++;
            right++;
        }
        for(int i=0;i<n+m;i++)
        {
             nums1[i]=ans[i];
            
        }
    }
};