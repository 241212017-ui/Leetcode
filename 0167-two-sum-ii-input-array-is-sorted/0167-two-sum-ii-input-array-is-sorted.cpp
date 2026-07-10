class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        int i =0 ;
        int  j= n-1;
        while(i<j){
            int sum = a[i] + a[j];
            if(sum ==target){
                return {i+1 ,j+1};
            }
            if(sum < target){
                i++;
            }
            else{
               j--;
            }
        }
        return {};
        
    }
};