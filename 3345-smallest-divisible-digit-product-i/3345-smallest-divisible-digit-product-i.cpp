class Solution {
public:
    int smallestNumber(int n, int t) {
       while (true) {
    int prod = 1;
    int cpy = n;

    while (cpy) {
        prod *= cpy % 10;
        cpy /= 10;
    }

    if (prod % t == 0)
        return n;

    n++;
}
return true;
    }
};