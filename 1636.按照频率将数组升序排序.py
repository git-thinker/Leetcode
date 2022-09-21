#
# @lc app=leetcode.cn id=1636 lang=python3
#
# [1636] 按照频率将数组升序排序
#
from typing import *
import collections
# @lc code=start
class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        counter = collections.Counter(nums)
        nums.sort(key=lambda x: (counter[x], -x))
        return nums

# @lc code=end

