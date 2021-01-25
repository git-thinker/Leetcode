#
# @lc app=leetcode.cn id=162 lang=python3
#
# [162] 寻找峰值
#

# @lc code=start
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        def get_item(index: int) -> int:
            if 0 <= index < len(nums):
                return nums[index]
            else:
                return -float('inf') 
        
        def verify(index: int) -> int:
            if get_item(index) > get_item(index - 1) and get_item(index) > get_item(index + 1):
                return 0
            elif get_item(index - 1) <= get_item(index) <= get_item(index + 1):
                return 1
            elif get_item(index - 1) >= get_item(index) >= get_item(index + 1):
                return -1
            else:
                return -1
            

        i, j = 0, len(nums) - 1
        m = (i + j) // 2
        while i < j:  
            flag = verify(m)
            if flag == 0:
                return m
            elif flag == 1:
                i = m + 1
            elif flag == -1:
                j = m
            m = (i + j) // 2
        return m
# @lc code=end

