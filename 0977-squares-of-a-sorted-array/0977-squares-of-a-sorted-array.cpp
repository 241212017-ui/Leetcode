class Solution {
public:
    vector<int> sortedSquares(vector<int>& ar) {

        vector<int> a;
        vector<int> b;

        int n = ar.size();

       
        for (int i = 0; i < n; i++) {
            if (ar[i] < 0)
                b.push_back(ar[i] * ar[i]);
            else
                a.push_back(ar[i] * ar[i]);
        }

    
        reverse(b.begin(), b.end());

        
        vector<int> ans;
        int i = 0, j = 0;

        while (i < b.size() && j < a.size()) {
            if (b[i] <= a[j]) {
                ans.push_back(b[i]);
                i++;
            } else {
                ans.push_back(a[j]);
                j++;
            }
        }

        while (i < b.size()) {
            ans.push_back(b[i]);
            i++;
        }

        while (j < a.size()) {
            ans.push_back(a[j]);
            j++;
        }

        return ans;
    }
};