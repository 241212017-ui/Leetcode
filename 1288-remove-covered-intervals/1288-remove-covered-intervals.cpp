class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& interval) {

        sort(interval.begin(), interval.end(), [&](vector<int>& a, vector<int>& b) {

            if (a[0] == b[0])
                return a[1] > b[1];

            return a[0] < b[0];
        });

        int ans = 0;
        int end = 0;

        for (int i = 0; i < interval.size(); i++) {
            int start1 = interval[i][0];
            int end1 = interval[i][1];

            if (end1 > end) {
                ans++;
                end = end1;
            }
        }

        return ans;
    }
};