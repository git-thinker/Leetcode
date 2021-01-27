#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#

# @lc code=start
List = list
class Solution:
    # import math
    # import random
    # def permute(self, nums: List[int]) -> List[List[int]]:
    #     rst = []
    #     while len(rst) != math.factorial(len(nums)):
    #         random.shuffle(nums)
    #         if nums not in rst:
    #             rst.append(nums[:])
    #     return rst
    def permute(self, nums: List[int]) -> List[List[int]]:
        rst = []
        tmp_rst = []
        hash_map = {}
        def recursive():
            if not nums:
                rst.append(tmp_rst[:])
                return None
            for item in nums[:]:
                tmp_rst.append(item)
                nums.remove(item)
                recursive()
                nums.append(item)
                tmp_rst.pop()
        recursive()
        return rst

# @lc code=end

