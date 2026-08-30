class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int n = nums.size();
       int minEleIdx = min_element(begin(nums) , end(nums)) -begin(nums);
       int maxEleIdx = max_element(begin(nums) , end(nums)) - begin(nums);
       int left = min(minEleIdx , maxEleIdx);
       int right = max(minEleIdx , maxEleIdx);
       return min({left+1+n-right , right+1 ,n-left});
    }
};