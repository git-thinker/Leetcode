#
# @lc app=leetcode.cn id=303 lang=python3
#
# [303] 区域和检索 - 数组不可变
#

# @lc code=start
class NumArray:

    def __init__(self, nums: List[int]):
        self.initData = nums
        self.preSum = []
        for item in self.initData:
            if self.preSum:
                self.preSum.append(self.preSum[-1] + item)
            else:
                self.preSum.append(item)

    def sumRange(self, i: int, j: int) -> int:
        lower = self.preSum[i-1] if i else 0
        upper = self.preSum[j]
        return upper - lower


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
# @lc code=end

