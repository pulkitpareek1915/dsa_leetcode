class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> stk;
        int n=nums.size();
        stk.push(nums[0]);
        for(int i=1;i<n;i++)
        {
           
                long long   num=nums[i];
                while(!stk.empty() && num==stk.top())
                {
                    stk.pop();
                    num=2*num;
                }
            
            
                stk.push(num);
            
        }
        vector<long long> ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};