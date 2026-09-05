class Solution {
public:
    int cnt = 0;
    void dfs(int node, vector<vector<pair<int, int>>>& adjls,
             vector<int>& vis) {
                vis[node]=1;
        for (auto it : adjls[node]) {
            if (it.first != node) {
                if (!vis[it.first]) {
                    cnt += it.second;
                    dfs(it.first, adjls, vis);
                }
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adjls(n);
        for (auto it : connections) {
            adjls[it[0]].push_back({it[1], 1});
            adjls[it[1]].push_back({it[0], 0});
        }
        vector<int> vis(n, 0);
        dfs(0, adjls, vis);
        return cnt;
    }
};