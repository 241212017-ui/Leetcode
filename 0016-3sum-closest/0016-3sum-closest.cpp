class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {

        sort(a.begin(), a.end());

        int n = a.size();
        int closest = a[0] + a[1] + a[2];

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = a[i] + a[left] + a[right];

                if (abs(target - sum) < abs(target - closest))
                    closest = sum;

                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else
                    return target;
            }
        }

        return closest;
    }
};