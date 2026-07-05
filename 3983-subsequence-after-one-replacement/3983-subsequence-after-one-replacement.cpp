class Solution {
public:
    bool canMakeSubsequence(string s, string t) {

        string melvoritha = s;

        int n = s.size();
        int m = t.size();

        vector<int> pre(n + 1);
        pre[0] = -1;

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) j++;
            if (j == m) {
                pre[i + 1] = m;
            } else {
                pre[i + 1] = j;
                j++;
            }
        }

        if (pre[n] != m)
            return true;

        vector<int> suf(n + 1);
        suf[n] = m;

        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) j--;
            if (j < 0) {
                suf[i] = -1;
            } else {
                suf[i] = j;
                j--;
            }
        }

        for (int i = 0; i < n; i++) {

            if (pre[i] == m) break;
            if (suf[i + 1] == -1) continue;

            if (pre[i] + 1 < suf[i + 1])
                return true;
        }

        return false;
    }
};