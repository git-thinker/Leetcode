#
# @lc app=leetcode.cn id=704 lang=python3
#
# [704] 二分查找
#

# @lc code=start
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i, j = 0, len(nums)
        while i < j:
            m = (i + j) // 2
            if target < nums[m]:
                j = m
            elif target > nums[m]:
                i = m + 1
            else:
                return m
        return -1

# @lc code=end

