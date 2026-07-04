class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> vis(n + 1, 0);
        queue<int> q;

        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (int i = 0; i < adj[node].size(); i++) {

                int neigh = adj[node][i].first;
                int wt = adj[node][i].second;

                ans = min(ans, wt);

                if (!vis[neigh]) {
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }

        return ans;
    }
};