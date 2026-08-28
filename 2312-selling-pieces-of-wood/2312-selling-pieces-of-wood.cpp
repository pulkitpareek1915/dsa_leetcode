class Solution {
public:
    long long solve(int row,
                    int col,
                    vector<vector<long long>>& price,
                    vector<vector<long long>>& dp)
    {
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }

        long long ans = price[row][col];

        for(int i = 1; i < row; i++)
        {
            ans = max(ans,
                      solve(i, col, price, dp) +
                      solve(row - i, col, price, dp));
        }

        
        for(int j = 1; j < col; j++)
        {
            ans = max(ans,
                      solve(row, j, price, dp) +
                      solve(row, col - j, price, dp));
        }

        return dp[row][col] = ans;
    }

    long long sellingWood(int m, int n, vector<vector<int>>& prices) {

        vector<vector<long long>> price(
            m + 1,
            vector<long long>(n + 1, 0)
        );

        for(auto &p : prices)
        {
            price[p[0]][p[1]] = p[2];
        }

        vector<vector<long long>> dp(
            m + 1,
            vector<long long>(n + 1, -1)
        );

        return solve(m, n, price, dp);
    }
};