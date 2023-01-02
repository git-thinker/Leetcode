#
# @lc app=leetcode.cn id=40 lang=python3
#
# [40] 组合总和 II
#
from typing import *
import collections
# @lc code=start
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        # set into counter
        counter = sorted(collections.Counter(candidates).items())
        ret = []
        cache = []
        def dfs(sum, idx):
            # dfs on counter
            if sum == target:
                ret.append(cache[:])
                return None
            if sum > target or idx >= len(counter):
                return None
            times = min(counter[idx][1], (target - sum) // counter[idx][0])
            i = 0
            while i <= times:
                # use item from 0 ~ largest possible 
                # so no duplicated
                dfs(sum, idx+1)
                cache.append(counter[idx][0])
                sum += counter[idx][0]
                i += 1
            for j in range(i):
                cache.pop()
                sum -= counter[idx][0]
        dfs(0, 0)
        return ret
# @lc code=end

