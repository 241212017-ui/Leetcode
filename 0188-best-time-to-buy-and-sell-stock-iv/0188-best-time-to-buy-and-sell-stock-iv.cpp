class Solution {
public:
    vector<vector<int>> dp;

    int fun(vector<int>& a, int n, int k, int i) {
        if (i == n || k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        if (k % 2 == 0) {      // Buy
            int buy = -a[i] + fun(a, n, k - 1, i + 1);
            int skip = fun(a, n, k, i + 1);
            return dp[i][k] = max(buy, skip);
        } else {               // Sell
            int sell = a[i] + fun(a, n, k - 1, i + 1);
            int skip = fun(a, n, k, i + 1);
            return dp[i][k] = max(sell, skip);
        }
    }

    int maxProfit(int x, vector<int>& a) {
        int n = a.size();

        if (x >= n / 2) {
            int ans = 0;
            for (int i = 1; i < n; i++) {
                if (a[i] > a[i - 1])
                    ans += a[i] - a[i - 1];
            }
            return ans;
        }

        dp.assign(n, vector<int>(2 * x + 1, -1));

        return fun(a, n, 2 * x, 0);
    }
};