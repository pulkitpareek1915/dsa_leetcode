class Solution {
public:
    int solve(int index, vector<int>& arr, int k, vector<int>& dp) {
        int n = arr.size();

        if (index == n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int maxi = 0;
        int ans = 0;

        for (int j = index; j < min(n, index + k); j++) {
            maxi = max(maxi, arr[j]);

            int len = j - index + 1;

            ans = max(ans, maxi * len + solve(j + 1, arr, k, dp));
        }

        return dp[index] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n, -1);

        return solve(0, arr, k, dp);
    }
};