class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& interval) {

        sort(interval.begin(), interval.end(),
             [&](vector<int>& a, vector<int>& b) {

            int start1 = a[0];
            int end1 = a[1];

            int start2 = b[0];
            int end2 = b[1];

            if (start1 == start2)
                return end1 > end2;

            return start1 < start2;
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