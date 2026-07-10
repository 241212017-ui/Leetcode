class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {

        sort(a.begin(), a.end());

        int n = a.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && a[i] == a[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int s = a[i] + a[left] + a[right];

                if (s == 0) {

                    res.push_back({a[i], a[left], a[right]});

                    left++;
                    right--;

                    while (left < right && a[left] == a[left - 1])
                        left++;

                    while (left < right && a[right] == a[right + 1])
                        right--;
                }

                else if (s < 0)
                    left++;

                else
                    right--;
            }
        }

        return res;
    }
};