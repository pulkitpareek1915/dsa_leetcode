class Solution {
public:
    int solve(int index, vector<int>& robber, vector<int>& dp)
    {
        if(index == 0)
            return robber[0];

        if(index < 0)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int pick = robber[index] + solve(index - 2, robber, dp);
        int notpick = solve(index - 1, robber, dp);

        return dp[index] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> robber1; // houses 0 to n-2
        vector<int> robber2; // houses 1 to n-1

        for(int i = 0; i < n - 1; i++)
            robber1.push_back(nums[i]);

        for(int i = 1; i < n; i++)
            robber2.push_back(nums[i]);

        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);

        int ans1 = solve(n - 2, robber1, dp1);
        int ans2 = solve(n - 2, robber2, dp2);

        return max(ans1, ans2);
    }
};