class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int sum = 0;
        int res = 0;

        unordered_map<int, int> freq;

        freq[0] = 1;

        for (int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            int ques = sum - k;

            if (freq.find(ques) != freq.end()) {
                res += freq[ques];
            }

            freq[sum]++;
        }

        return res;
    }
};