class Solution {
public:
    bool check(int mid, vector<vector<pair<int, int>>>& g, int n, long long k)
    {
        vector<long long> dis(n, LLONG_MAX);

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> q;

        dis[0] = 0;
        q.push({0, 0});

        while (!q.empty())
        {
            auto [d, u] = q.top();
            q.pop();

            if (d > k)
                return false;

            if (u == n - 1)
                return true;

            if (d > dis[u])
                continue;

            for (auto &it : g[u])
            {
                int v = it.first;
                int w = it.second;

                if (w < mid)
                    continue;

                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k)
    {
        int n = online.size();

        vector<vector<pair<int, int>>> g(n);

        int l = INT_MAX;
        int r = 0;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (!online[u] || !online[v])
                continue;

            g[u].push_back({v, w});

            l = min(l, w);
            r = max(r, w);
        }

        if (!check(l, g, n, k))
            return -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (check(mid, g, n, k))
                l = mid + 1;
            else
                r = mid - 1;
        }

        return r;
    }
};