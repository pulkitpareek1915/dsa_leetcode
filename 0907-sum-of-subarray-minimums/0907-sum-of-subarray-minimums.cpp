class Solution {
public:
    vector<int> findnse(vector<int>& arr)
    {
        int n=arr.size();
        stack<int> stk;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            int curr=arr[i];
            while(!stk.empty() && curr<=arr[stk.top()])
            {
                stk.pop();
            }
            if(stk.empty())
            {
                ans[i]=n;
            }
            else{
                ans[i]=stk.top();
            }
            stk.push(i);
        }
        return ans;
    }
    vector<int> findpse(vector<int>& arr)
    {
        int n=arr.size();
        stack<int> stk;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int curr=arr[i];
            while(!stk.empty() && curr<arr[stk.top()])
            {
                stk.pop();
            }
            if(stk.empty())
            {
                ans[i]=-1;
            }
            else{
                ans[i]=stk.top();
            }
            stk.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse=findnse(arr);
        vector<int> pse=findpse(arr);
        long long sum = 0;
        const int mod = 1e9 + 7;
        for(int i=0;i<n;i++)
        {
            int left=i-pse[i];
            int right=nse[i]-i;
            long long freq = 1LL * left * right;
            long long val = (freq * arr[i]) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
    
};