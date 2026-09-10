class Solution {
public:
    int const mod = 1e9 + 7;
    int solve(int i, int j, int moves, vector<vector<vector<int>>>& dp, int m,
              int n) {

        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 1;
        }
        if (moves == 0)
            return 0;
        if (dp[i][j][moves] != -1) {
            return dp[i][j][moves];
        }
        int up = solve(i - 1, j, moves - 1, dp, m, n);
        int left = solve(i, j - 1, moves - 1, dp, m, n);
        int down = solve(i + 1, j, moves - 1, dp, m, n);
        int right = solve(i, j + 1, moves - 1, dp, m, n);
        return dp[i][j][moves] =
                   (((up + down) % mod + left) % mod + right) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(startRow, startColumn, maxMove, dp, m, n);
    }
};