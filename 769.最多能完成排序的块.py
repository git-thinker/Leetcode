#
# @lc app=leetcode.cn id=769 lang=python3
#
# [769] 最多能完成排序的块
#
from typing import *
# @lc code=start
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        ret = 0
        cache_a, cache_b = 0, 0
        for i, item in enumerate(arr):
            cache_a += i
            cache_b += item
            if cache_a == cache_b:
                ret += 1
        return ret
# @lc code=end

