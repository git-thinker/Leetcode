#
# @lc app=leetcode.cn id=1047 lang=python3
#
# [1047] 删除字符串中的所有相邻重复项
#

# @lc code=start
class Solution:
    def removeDuplicates(self, S: str) -> str:
        if len(S) <= 1:
            return S
        i, j = 0, 1
        S = list(S)
        while j < len(S):
            if i < 0:
                i += 1
                S[i] = S[j]
            else:
                if S[i] != S[j]:
                    i += 1
                    S[i] = S[j]
                else:
                    i -= 1
            j += 1

        return ''.join(S[:i+1])
# @lc code=end

