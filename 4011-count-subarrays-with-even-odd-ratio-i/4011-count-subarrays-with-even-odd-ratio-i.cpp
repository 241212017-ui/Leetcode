class Solution {
public:
    long long ans = 0;

    void mergeSort(vector<long long>& pre, int l, int r) {

        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergeSort(pre, l, mid);
        mergeSort(pre, mid + 1, r);

        int i = l;
        int j = mid + 1;

        while (i <= mid && j <= r) {
            if (pre[i] >= pre[j]) {
                ans += (mid - i + 1);
                j++;
            } else {
                i++;
            }
        }

        i = l;
        j = mid + 1;

        vector<long long> temp;

        while (i <= mid && j <= r) {
            if (pre[i] <= pre[j])
                temp.push_back(pre[i++]);
            else
                temp.push_back(pre[j++]);
        }

        while (i <= mid)
            temp.push_back(pre[i++]);

        while (j <= r)
            temp.push_back(pre[j++]);

        for (int k = l; k <= r; k++)
            pre[k] = temp[k - l];
    }

    long long countRatioSubarrays(vector<int>& nums, int a, int b) {

        int n = nums.size();

        vector<long long> pre(n + 1, 0);

        int even = 0, odd = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] & 1)
                odd++;
            else
                even++;

            pre[i + 1] = 1LL * b * even - 1LL * a * odd;
        }

        mergeSort(pre, 0, n);

        return ans;
    }
};