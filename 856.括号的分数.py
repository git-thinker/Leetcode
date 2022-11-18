#
# @lc app=leetcode.cn id=856 lang=python3
#
# [856] 括号的分数
#

# @lc code=start
class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        ret = 0
        left = 0
        for i in range(len(s)):
            if s[i] == '(':
                left += 1
            else:
                left -= 1
                if s[i-1] == '(':
                    ret += 1 * 2 ** left
        return ret


# @lc code=end

