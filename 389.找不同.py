#
# @lc app=leetcode.cn id=389 lang=python3
#
# [389] 找不同
#

# @lc code=start
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        mapping_s = {}
        mapping_t = {}
        for i, item in enumerate(s):
            if item in mapping_s:
                mapping_s[item] += 1
            else:
                mapping_s[item] = 1
        
        for i, item in enumerate(t):
            if item in mapping_t:
                mapping_t[item] += 1
            else:
                mapping_t[item] = 1
        
        for i in mapping_t.keys():
            if i in mapping_s:
                if mapping_s[i] != mapping_t[i]:
                    return i
            else:
                return i
# @lc code=end

