#
# @lc app=leetcode.cn id=31 lang=python3
#
# [31] 下一个排列
#

# @lc code=start
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Find the last ascending slice
        # change the first with the smallest item which is just larger than the first element
        
        # is there any ascending slice?
        flag = False
        
        # start of ascending slice
        j = 0
        for i in range(len(nums)-1):
            if nums[i] < nums[i+1]:
                flag = True
                j = i
        
        # all descending then return sorted
        if not flag:
            nums.sort()
            return None
        
        # find the smallest which is just larger than the first
        k = j + 1
        for i in range(j+1, len(nums)):
            if nums[j] < nums[i] < nums[k]:
                k = i
                
        # change
        nums[j], nums[k] = nums[k], nums[j]
        
        # sort the appendix
        nums[j+1:] = sorted(nums[j+1:])
        return None
# @lc code=end

