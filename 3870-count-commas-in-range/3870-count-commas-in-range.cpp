class Solution {
public:
    int countCommas(int n) {
        int count  =0;
       if(n< 1000) return 0;
       for(int num =1000; num<=n ; num++){
        count +=1;
       }
  return count;
    }
};