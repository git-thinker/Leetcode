#
# @lc app=leetcode.cn id=561 lang=python3
#
# [561] 数组拆分 I
#

# @lc code=start
import collections
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])       
# @lc code=end

