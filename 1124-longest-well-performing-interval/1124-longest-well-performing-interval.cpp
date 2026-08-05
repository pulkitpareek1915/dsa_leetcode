class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
       // vector<int> prefix(n);
        int ps=0;
        for(int i=0;i<n;i++)
        {
            if(hours[i]>8)
            {
                hours[i]=1;
            }
            else{
                hours[i]=-1;
            }
        }
        unordered_map<int,int> mpp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ps+=hours[i];
            if(ps>0)
            {
                ans=i+1;
            }
            else{
                if(mpp.find(ps-1)!=mpp.end())
                {
                    ans=max(ans,i-mpp[ps-1]);
                }
            }
            if(mpp.find(ps)==mpp.end())
            {
                mpp[ps]=i;
            }
        }
        return ans;
    }
};