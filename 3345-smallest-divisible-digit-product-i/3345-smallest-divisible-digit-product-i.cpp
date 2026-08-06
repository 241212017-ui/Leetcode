class Solution {
public:
    int smallestNumber(int n, int t) {
       while(1){
        int prod =1;
        int cpy = n;
        while(cpy){
            int rightmost = cpy%10;
            prod = prod *rightmost;
            cpy = cpy/10;

        }
        if(prod %t==0) return n;
            n++;
        
       }
       return 1; 
    }
};