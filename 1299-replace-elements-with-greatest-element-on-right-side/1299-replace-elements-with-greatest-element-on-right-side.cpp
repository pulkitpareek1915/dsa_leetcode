class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,-1);
        int maxi=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxi=max(maxi,arr[i+1]);
            ans[i]=maxi;
        }
        return ans;
    }
};