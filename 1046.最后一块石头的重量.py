#
# @lc app=leetcode.cn id=1046 lang=python3
#
# [1046] 最后一块石头的重量
#

# @lc code=start
import heapq
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        self.stones = [-item for item in stones]
        heapq.heapify(self.stones)
        while len(self.stones) > 1:
            x = -heapq.heappop(self.stones)
            y = -heapq.heappop(self.stones)
            if x > y:
                x, y = y, x
            if x != y:
                heapq.heappush(self.stones, x-y)
        return 0 if not self.stones else -self.stones[0]

        
# @lc code=end

