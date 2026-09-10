class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit =0;
        int current = prices[0];
        for(int  i =0 ; i< prices.size(); i++){
            current = min(current , prices[i]);
            int profit = prices[i] - current;
            maxprofit = max(profit , maxprofit);
        }
         return maxprofit;
    }
};