class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum<0)
            {
                sum=0;
            }
            maxi=max(sum,maxi);
        }
        int sum2=0;
        int maxi2=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum2+=nums[i];
            if(sum2>0)
            {
                sum2=0;
            }
            maxi2=min(sum2,maxi2);
            cout<<maxi2<<endl;
        }
        return max(maxi,abs(maxi2));
    }
};