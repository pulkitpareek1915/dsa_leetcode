class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n=s.size();
        vector<int> nums(n,0);
        vector<int> cha(26,-1001);
        for(int i=0;i<chars.size();i++)
        {
            char c=chars[i];
            int index=c-'a';
            cha[index]=vals[i];
        }
        for(int i=0;i<26;i++)
        {
            if(cha[i]==-1001)
            {
                cha[i]=i+1;
            }
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=cha[s[i]-'a'];
        }
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum<0)
            {
                sum=0;
            }
            maxi=max(maxi,sum);
        }
         return maxi;
    }
};