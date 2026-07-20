class Solution {
public:
    int findMaxLength(vector<int>& n) {

        int zero = 0;
        int one = 0;
        int res = 0;

        unordered_map<int, int> freq;

        freq[0] = -1;

        for(int i = 0; i < n.size(); i++) {

            if(n[i] == 0) {
                zero++;
            }
            else {
                one++;
            }

            int diff = zero - one;

            
            if(freq.find(diff) != freq.end()) {

                int index = freq[diff];

                int len = i - index;

                res = max(res, len);
            }
            else {
                
                freq[diff] = i;
            }
        }

        return res;
    }
};