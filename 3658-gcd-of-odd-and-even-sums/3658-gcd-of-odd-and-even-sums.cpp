class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum =0 ;
        int  evenSum = 0;

        for(int i =1 ; i<2*n;  i++){
            if(i%2){
                oddSum += i;
            }
            else{
                evenSum += i
;
            }
        }
        return gcd(oddSum , evenSum);
        
    }
};