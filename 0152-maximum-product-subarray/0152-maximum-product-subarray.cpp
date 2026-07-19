class Solution {
public:
    int maxProduct(vector<int>& a) {
        int minending = a[0];
        int maxending = a[0];
        int res = a[0];
        for(int i =1 ; i<a.size(); i++){
            int v1 = a[i];
            int v2 = minending *a[i];
            int v3 = maxending*a[i];
            maxending = max(v1 , max(v2 , v3));
            minending = min(v1 , min(v2 , v3));
            res = max(res, max(maxending , minending));
        }
        return res;
    }
};