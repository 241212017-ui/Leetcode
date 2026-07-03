class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        int low = 0, high = 0;
        for (auto &e : edges)
            high = max(high, e[2]);

        auto check = [&](int mn) {

            vector<vector<pair<int,int>>> adj(n);
            vector<int> indegree(n, 0);

            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];

                if (w < mn) continue;

                if (u != 0 && u != n - 1 && !online[u]) continue;
                if (v != 0 && v != n - 1 && !online[v]) continue;

                adj[u].push_back({v, w});
                indegree[v]++;
            }

            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0)
                    q.push(i);
            }

            vector<long long> dist(n, LLONG_MAX);
            dist[0] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto &it : adj[u]) {
                    int v = it.first;
                    int w = it.second;

                    if (dist[u] != LLONG_MAX)
                        dist[v] = min(dist[v], dist[u] + w);

                    indegree[v]--;
                    if (indegree[v] == 0)
                        q.push(v);
                }
            }

            return dist[n - 1] <= k;
        };

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};