#
# @lc app=leetcode.cn id=1790 lang=python3
#
# [1790] 仅执行一次字符串交换能否使两个字符串相等
#

# @lc code=start
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        cnt = 0
        bak = ''
        for i, j in zip(s1, s2):
            if i != j:
                cnt += 1
                if cnt == 1:
                    bak = j + i
                if cnt > 2:
                    return False
                elif cnt == 2:
                    if i + j != bak:
                        return False
        return cnt == 2 or cnt == 0
# @lc code=end
