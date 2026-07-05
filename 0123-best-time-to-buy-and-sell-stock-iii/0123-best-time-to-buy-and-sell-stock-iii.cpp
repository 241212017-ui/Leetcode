class Solution {
public:
    int dp[100001][5];

    int fun(vector<int>& a, int n, int k, int i) {
        if (i == n || k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        if (k % 2 == 0) {           // Buy
            int buy = -a[i] + fun(a, n, k - 1, i + 1);
            int skip = fun(a, n, k, i + 1);
            return dp[i][k] = max(buy, skip);
        } else {                    // Sell
            int sell = a[i] + fun(a, n, k - 1, i + 1);
            int skip = fun(a, n, k, i + 1);
            return dp[i][k] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& a) {
        memset(dp, -1, sizeof(dp));
        return fun(a, a.size(), 4, 0);
    }
};