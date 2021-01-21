#
# @lc app=leetcode.cn id=27 lang=python3
#
# [27] 移除元素
#

# @lc code=start
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i, j = 0, len(nums) - 1
        while i <= j:
            if nums[i] == val:
                if nums[i] != nums[j]:
                    nums[i], nums[j] = nums[j], nums[i]
                j -= 1
            else:
                i += 1
        return j + 1

# @lc code=end

