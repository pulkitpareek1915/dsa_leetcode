class Solution {
public:
    int solve(int index,vector<int> &distribute,vector<int>& cookies,
    int k,int zero_count,int n)
    {
        if(zero_count>n-index)
        {
            return INT_MAX;
        }
        if(index==n)
        {
            return *max_element(distribute.begin(),distribute.end());
        }
        int ans=INT_MAX;
        for(int j=0;j<k;j++)
        {
            zero_count-=distribute[j]==0?1:0;
            distribute[j]+=cookies[index];
            ans=min(ans,solve(index+1,distribute,cookies,k,zero_count,n));
            zero_count+=distribute[j]==0?1:0;
            distribute[j]-=cookies[index];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribute(k,0);
        int n=cookies.size();
        return solve(0,distribute,cookies,k,k,n);
    }
};