class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a,
                               vector<int>& newInterval) {

        vector<vector<int>> res;

        int start = newInterval[0];
        int end = newInterval[1];

        bool inserted = false;

        for(int i = 0; i < a.size(); i++) {

           
            if(a[i][1] < start) {
                res.push_back(a[i]);
            }

          
            else if(a[i][0] > end) {

                if(inserted == false) {
                    res.push_back({start, end});
                    inserted = true;
                }

                res.push_back(a[i]);
            }

          
            else {

                start = min(start, a[i][0]);
                end = max(end, a[i][1]);
            }
        }

        if(inserted == false) {
            res.push_back({start, end});
        }

        return res;
    }
};