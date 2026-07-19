class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {

        
        int bestendingMax = a[0];
        int ansMax = a[0];

        
        int bestendingMin = a[0];
        int ansMin = a[0];

        for (int i = 1; i < a.size(); i++) {

        
            bestendingMax = max(a[i], bestendingMax + a[i]);

            ansMax = max(ansMax, bestendingMax);

        
            bestendingMin = min(a[i], bestendingMin + a[i]);

            ansMin = min(ansMin, bestendingMin);
        }

        return max(ansMax, abs(ansMin));
    }
};