class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> d;

        while (n > 0) {
            if (n % 10 != 0)
                d.push_back(n % 10);
            n /= 10;
        }

        reverse(d.begin(), d.end());

        long long x = 0, sum = 0;

        for (int i = 0; i < d.size(); i++) {
            x = x * 10 + d[i];
            sum += d[i];
        }

        return x * sum;
    }
};