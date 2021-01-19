#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapping = {}
        for i in range(len(nums)):
            if nums[i] in mapping:
                return [mapping[nums[i]], i]
            else:
                mapping[target - nums[i]] = i
# @lc code=end

