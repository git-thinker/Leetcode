#
# @lc app=leetcode.cn id=128 lang=python3
#
# [128] 最长连续序列
#

# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        ans = 1 if nums else 0
        tmp = 1
        for i in range(len(nums) - 1):
            if nums[i+1] - nums[i] == 1:
                tmp += 1
            elif nums[i+1] - nums[i] == 0:
                pass
            if tmp > ans:
                ans = tmp
            if nums[i+1] - nums[i] > 1:
                tmp = 1
        return ans
            
# @lc code=end

