#
# @lc app=leetcode.cn id=287 lang=python3
#
# [287] 寻找重复数
#

# @lc code=start
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        hash_map = {}
        for item in nums:
            if item in hash_map:
                return item
            else:
                hash_map[item] = True
# @lc code=end

