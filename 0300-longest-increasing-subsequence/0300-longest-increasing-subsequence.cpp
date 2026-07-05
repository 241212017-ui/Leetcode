class Solution {
public:
    int lengthOfLIS(vector<int>& a) {

        int n = a.size();

        if (n == 0)
            return 0;

        vector<int> res(n, 1);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (a[j] < a[i]) {
                    res[i] = max(res[i], res[j] + 1);
                }
            }
        }

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, res[i]);
        }

        return ans;
    }
};