class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<long long,long long > mpp;
        vector<int> ans;
        for(long long  i=1;i*i*i<=n;i++)
            {
                for(long long j=i;j*j*j<=n;j++)
                    {
                        int sum=i*i*i+j*j*j;
                        if(sum<=n)
                        {
                            mpp[sum]++;
                        }
                    }
            }
        for(auto it:mpp){
            if(it.second>=2){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};