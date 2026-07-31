class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n=nums.size();
        vector<int> num(2*n);
        for(int i=0;i<n;i++)
        {
            num[i]=nums[i];
        }
        for(int i=n;i<2*n;i++)
        {
            num[i]=nums[i-n];
        }
       
        vector<int> ans(2*n);
        //stk.push(-1);
        for(int i=2*n-1;i>=0;i--)
        {
            int curr=num[i];
            while((!(stk.empty()) && stk.top()<=curr))
            {
                stk.pop();
            }
            if(stk.empty())
            {
                ans[i]=-1;
            }
            else
            {
                ans[i]=stk.top();
            }
            stk.push(curr);
        }
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            a[i]=ans[i];
        }
        return a;
    }
};