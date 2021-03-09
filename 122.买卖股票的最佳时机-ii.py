#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # return sum([profit for profit in [prices[i+1]-prices[i] for i in range(len(prices)-1)] if profit > 0])
        profit = 0
        i, j = 0, 1
        while j < len(prices):
            if prices[j-1] < prices[j]:
                pass
            elif prices[j-1] > prices[j]:
                if j - i > 1:
                    profit += prices[j-1] - prices[i]
                i = j
            j += 1
        if j-1 != i:
            profit += prices[j-1] - prices[i]

        return profit

# @lc code=end

