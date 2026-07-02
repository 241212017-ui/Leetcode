class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> dq;

        minCost[0][0] = grid[0][0];
        dq.push_front({0, 0});

        int dRow[4] = {-1, 1, 0, 0};
        int dCol[4] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto curr = dq.front();
            dq.pop_front();

            int r = curr.first;
            int c = curr.second;

            if (r == m - 1 && c == n - 1) {
                return minCost[r][c] < health;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dRow[i];
                int nc = c + dCol[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int cost = grid[nr][nc];

                    if (minCost[r][c] + cost < minCost[nr][nc]) {
                        minCost[nr][nc] = minCost[r][c] + cost;

                        if (cost == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }

        return minCost[m - 1][n - 1] < health;
    }
};