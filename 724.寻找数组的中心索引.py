#
# @lc app=leetcode.cn id=724 lang=python3
#
# [724] 寻找数组的中心索引
#

# @lc code=start
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        if not nums:
            return -1
        accumulation = list(itertools.accumulate(nums))
        summation = accumulation[-1]
        for i in range(len(nums)):
            if summation - accumulation[i] == accumulation[i] - nums[i]:
                return i
        return -1
# @lc code=end

