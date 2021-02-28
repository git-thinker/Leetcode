#
# @lc app=leetcode.cn id=171 lang=python3
#
# [171] Excel表列序号
#

# @lc code=start
class Solution:
    def titleToNumber(self, s: str) -> int:
        l = len(s)
        return sum([26**(l - i - 1) * (ord(s[i]) - 64) for i in range(l)])
# @lc code=end

