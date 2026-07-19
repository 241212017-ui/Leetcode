class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        int maxEnding = nums[0];
        int maxSum = nums[0];

        int minEnding = nums[0];
        int minSum = nums[0];

        total = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            total += nums[i];

            maxEnding = max(nums[i], maxEnding + nums[i]);
            maxSum = max(maxSum, maxEnding);

            minEnding = min(nums[i], minEnding + nums[i]);
            minSum = min(minSum, minEnding);
        }

        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};