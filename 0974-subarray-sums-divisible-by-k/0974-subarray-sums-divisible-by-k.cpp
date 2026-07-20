class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n = a.size();
        int sum = 0; int res =0;
        unordered_map<int ,int> freq; 
        freq[0] = 1;
        for(int  i = 0; i< n; i++){
            sum += a[i];
            int rem = sum % k;
            if(rem < 0){
                rem = rem + k;
            }
             res += freq[rem];
              freq[rem]++;
        }
    
        return res;
    }
};