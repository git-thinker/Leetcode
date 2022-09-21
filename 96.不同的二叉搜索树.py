#
# @lc app=leetcode.cn id=96 lang=python3
#
# [96] 不同的二叉搜索树
#
from functools import cache
# @lc code=start
class Solution:
    def numTrees(self, n: int) -> int:
        return self.recursive(n)
    @cache
    def recursive(self, n: int):
        if n <= 1:
            return 1
        if n == 2:
            return 2
        ret = 0
        for i in range((n - 1) // 2 + 1):
            if n % 2 and i == (n - 1) / 2:
                ret += self.recursive(i) * self.recursive(n - 1 - i)
            else:
                ret += self.recursive(i) * self.recursive(n - 1 - i) * 2
        return ret
# @lc code=end
