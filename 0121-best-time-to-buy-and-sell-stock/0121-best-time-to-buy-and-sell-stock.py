class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit = 0
        current = prices[0]
        for i in range(len(prices)):
            current = min(current , prices[i])
            profit = prices[i] - current
            maxprofit =max(profit , maxprofit)


        return maxprofit