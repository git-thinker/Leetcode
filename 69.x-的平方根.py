#
# @lc app=leetcode.cn id=69 lang=python3
#
# [69] x 的平方根
#

# @lc code=start
class Solution:
    def mySqrt(self, x: int) -> int:
        lo = 0
        hi = x // 2 + 1
        while lo < hi:
            m = (lo + hi) >> 1
            a = m ** 2
            b = (m + 1)**2
            if a <= x < b:
                return m
            elif x < a:
                hi = m
            else:
                lo = m + 1
        if lo == hi:
            a = lo ** 2
            b = (lo + 1)**2
            if a <= x < b:
                return lo
Solution().mySqrt(1)
# @lc code=end

