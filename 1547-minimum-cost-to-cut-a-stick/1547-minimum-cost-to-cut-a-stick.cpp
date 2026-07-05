class Solution {
public:
    vector<vector<int>> dp;

    int fun(vector<int>& cuts, int i, int j) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;

        for (int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1];
            int cur = cost + fun(cuts, i, k - 1) + fun(cuts, k + 1, j);
            res = min(res, cur);
        }

        return dp[i][j] = res;
    }

    int minCost(int n, vector<int>& c) {
        vector<int> cuts;

        cuts.push_back(0);

        for (int x : c)
            cuts.push_back(x);

        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int s = cuts.size();

        dp.assign(s, vector<int>(s, -1));

        return fun(cuts, 1, s - 2);
    }
};