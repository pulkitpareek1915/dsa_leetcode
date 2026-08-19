class Solution {
public:
    bool static comp(vector<int> a, vector<int> b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    int solve(int index, vector<vector<int>>& mat, int n, vector<int>& dp,
              vector<int>& startTime) {
        if (index >= n) {
            return 0;
        }
        if (dp[index] != -1)
            return dp[index];
        int profit = INT_MIN;
        // int next=index+1;
        // while (next < n && mat[index][1] > mat[next][0]) {
        //     next++;
        // }
        int next =
            lower_bound(startTime.begin(), startTime.end(), mat[index][1]) -
            startTime.begin();
        int take = mat[index][2] + solve(next, mat, n, dp, startTime);
        int nottake = solve(index + 1, mat, n, dp, startTime);
        profit = max(take, nottake);
        return dp[index] = profit;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> mat(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            mat[i][0] = startTime[i];
            mat[i][1] = endTime[i];
            mat[i][2] = profit[i];
        }
        sort(mat.begin(), mat.end(), comp);
        vector<int> starts;
        for (auto& job : mat) {
            starts.push_back(job[0]);
        }
        vector<int> dp(n + 1, -1);
        return solve(0, mat, n, dp, starts);
    }
};