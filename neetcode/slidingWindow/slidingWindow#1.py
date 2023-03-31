from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 1:
            return 0
        ret, m = 0, 0
        i = 1
        while i < len(prices):
            if prices[i] - prices[m] > ret:
                ret = prices[i] - prices[m]
            if prices[i] < prices[m]:
                m = i
            i += 1
        return ret