#
# @lc app=leetcode.cn id=189 lang=python3
#
# [189] 旋转数组
#

# @lc code=start
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        store = []
        k %= len(nums)
        for _ in range(k):
            store.append(nums.pop())
        while store:
            nums.insert(0, store.pop(0))
       
            
# @lc code=end

