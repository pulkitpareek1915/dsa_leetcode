class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int even=0;
        int odd=0;
        for(int i=0;i<n;i++)
            {
                if(nums1[i]%2==0)
                {
                    even++;
                }
                else{
                    odd++;
                }
            }
        sort(nums1.begin(),nums1.end());
        if(even==n || odd==n)
        {
            return true;
        }
        if(nums1[0]%2==1)
        {
            return true;
        }
        if(nums1[0]%2==0)
        {
            if(even==n)
            {
                return true;
            }
            else{
                return false;
            }
        }
        return true;
    }
};