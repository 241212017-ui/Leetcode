class Solution {
public:
    long long countCommas(long long n) {
   long long result =0;
   long long lower = 1000;
   long long comma =1;
   while(lower <= n){
    long long upper = lower *1000 -1;
    if(upper > n) upper =n;
    long long countnumber = (upper - lower +1);
    result += (countnumber*comma);
    lower = (lower*1000);
    comma += 1;
   }
   return result;;
    }
};