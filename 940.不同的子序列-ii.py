#
# @lc app=leetcode.cn id=940 lang=python3
#
# [940] 不同的子序列 II
#

# @lc code=start

class Solution:
    def distinctSubseqII(self, s: str) -> int:
        mod = 10**9 + 7
        last = [-1] * 26

        n = len(s)
        f = [1] * n
        for i, ch in enumerate(s):
            for j in range(26):
                if last[j] != -1:
                    f[i] = (f[i] + f[last[j]]) % mod
            last[ord(s[i]) - ord("a")] = i
        
        ans = 0
        for i in range(26):
            if last[i] != -1:
                ans = (ans + f[last[i]]) % mod
        return ans
# @lc code=end

