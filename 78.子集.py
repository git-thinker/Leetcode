#
# @lc app=leetcode.cn id=78 lang=python3
#
# [78] 子集
#

# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        rst = [[]]
        for each in nums:
            for item in rst[:]:
                item = item[:]
                item.append(each)
                rst.append(item)
        return rst
# @lc code=end

