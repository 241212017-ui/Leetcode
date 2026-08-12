class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i  =0;
        int n = nums.size();
        int j =0 ;
        int result =0;
        unordered_map<int , int> f;
      while(j<n){
        f[nums[j]]++;
      
      while(i<j && f[nums[j]]>k){
         f[nums[i]]--;
         i++;
      }
        
        result =max(result , j -i +1);
        j++;
       } 
       return result;
    }
};