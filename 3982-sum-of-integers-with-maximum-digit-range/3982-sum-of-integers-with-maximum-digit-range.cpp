class Solution {
public:
    int digitRange(int x) {
        if (x == 0) return 0;

        int mx = 0;
        int mn = 9;

        while (x > 0) {
            int d = x % 10;
            mx = max(mx, d);
            mn = min(mn, d);
            x /= 10;
        }

        return mx - mn;
    }

    int maxDigitRange(vector<int>& nums) {

        int mxRange = -1;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            mxRange = max(mxRange, digitRange(nums[i]));
        }

        for (int i = 0; i < nums.size(); i++) {
            if (digitRange(nums[i]) == mxRange) {
                ans += nums[i];
            }
        }

        return ans;
    }
};