#
# @lc app=leetcode.cn id=136 lang=python3
#
# [136] 只出现一次的数字
#

# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        if len(nums) != 1:
            for i in range(1, len(nums)):
                nums[i] = nums[i] ^ nums[i-1]
        return nums[-1]
# @lc code=end

