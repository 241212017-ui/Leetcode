class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int total = 0;
    
        for(int num : nums) {
            total += num;
        }

        int left = 0;

        for(int i = 0; i < nums.size(); i++) {

            int right = total - nums[i] - left;

            if(left == right) {
                return i;
            }

            left += nums[i];
        }

        return -1;
    }
};