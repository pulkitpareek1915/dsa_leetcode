class Solution {
public:
    const int mod=1e9+7;
    int solve(int index, int steps, int arrLen,vector<vector<int>> &dp) {
        if (steps == 0) {
            return index == 0;
        }
        if(dp[index][steps]!=-1){
            return dp[index][steps];
        }
        long long right = 0;
        long long left = 0;
        long long stay = 0;
        if (steps >= 1) {
            if (index + 1 < arrLen) {
                right = solve(index + 1, steps - 1, arrLen,dp);
            }

            if (index >= 1) {
                left = solve(index - 1, steps - 1, arrLen,dp);
            }
            stay = solve(index, steps - 1, arrLen,dp);
        }

        return dp[index][steps]=((right + left)%mod + stay)%mod;
    }
    int numWays(int steps, int arrLen) 
    {
        int limit = min(arrLen, steps + 1);
        vector<vector<int>> dp(limit,vector<int>(steps+1,-1));
        return solve(0, steps, arrLen,dp); 
    }
};