class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       int multiple = k;
       while(true){
        bool found = false;
        for(int val : nums){
            if(val == multiple){
                found = true;
                break;
            }
        }
            if(!found){
                return multiple;
            }
        
       
       multiple += k;
       }
    }
};