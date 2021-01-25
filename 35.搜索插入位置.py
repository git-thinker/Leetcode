#
# @lc app=leetcode.cn id=35 lang=python3
#
# [35] 搜索插入位置
#

# @lc code=start
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        i, j  = 0, len(nums)
        while i < j:
            m = (i + j) // 2
            if target <= nums[m]:
                j = m
            else:
                i = m + 1
        return i

# @lc code=end

