#
# @lc app=leetcode.cn id=1894 lang=python3
#
# [1894] 找到需要补充粉笔的学生编号
#

# @lc code=start
class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        s = sum(chalk)
        k %= s
        for i in range(0, len(chalk)):
            if chalk[i] > k:
                break
            else:
                k -= chalk[i]
        return i        
# @lc code=end

