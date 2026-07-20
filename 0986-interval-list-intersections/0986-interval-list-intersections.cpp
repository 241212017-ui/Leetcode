class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a,
                                             vector<vector<int>>& b) {

        vector<vector<int>> res;

        int i = 0;
        int j = 0;

        while(i < a.size() && j < b.size()) {

            int start1 = a[i][0];
            int end1 = a[i][1];

            int start2 = b[j][0];
            int end2 = b[j][1];

            if(start1 <= start2) {

                if(end1 >= start2) {

                    int start = max(start1, start2);
                    int end = min(end1, end2);

                    res.push_back({start, end});
                }
            }

            else {

                if(end2 >= start1) {

                    int start = max(start1, start2);
                    int end = min(end1, end2);

                    res.push_back({start, end});
                }
            }

            if(end1 <= end2) {
                i++;
            }

            else {
                j++;
            }
        }

        return res;
    }
};