class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> freq(101 ,0);
   int minEle =  INT_MAX;
   int maxEle = INT_MIN;
   for(auto &val : nums){
    freq[val] =1;
    maxEle = max(maxEle , val);
    minEle = min(minEle , val);
   }
   vector<int> ans;
   for(int i = minEle+1;  i< maxEle;  i++){
   if(freq[i] ==0){
    ans.push_back(i);
   }
   }
   return ans;
    }
};