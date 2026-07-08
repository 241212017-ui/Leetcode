class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> preSum(n + 1, 0), preCnt(n + 1, 0);
        vector<long long> preVal(n + 1, 0), p10(n + 1, 1);

        for (int i = 1; i <= n; i++)
            p10[i] = (p10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i];
            preCnt[i + 1] = preCnt[i];
            preVal[i + 1] = preVal[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                preSum[i + 1] += d;
                preCnt[i + 1]++;
                preVal[i + 1] = (preVal[i] * 10 + d) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long sum = preSum[r + 1] - preSum[l];
            long long cnt = preCnt[r + 1] - preCnt[l];

            long long x = (preVal[r + 1] - preVal[l] * p10[cnt]) % MOD;
            x = (x + MOD) % MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};