class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int low = 0;
        int zeroCount = 0;
        int ans = 0;

        for (int high = 0; high < nums.size(); high++) {

            if (nums[high] == 0)
                zeroCount++;

            while (zeroCount > k) {

                if (nums[low] == 0)
                    zeroCount--;

                low++;
            }

            ans = max(ans, high - low + 1);
        }

        return ans;
    }
};