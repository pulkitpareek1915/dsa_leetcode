class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right=0;
        int left=m-1;
    
        while (left >= 0 && right < n && nums1[left] > nums2[right])
        {
            swap(nums1[left],nums2[right]);
            right++;
            left--;
        }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.begin()+n);
        for(int i=m;i<n+m;i++)
        {
            nums1[i]=nums2[i-m];
        }
    }
};