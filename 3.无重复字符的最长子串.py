#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        length = 0
        record = {}
        i, j, n, max_length = 0, 1, 1, 1
        record[s[i]] = i
        while j < len(s):
            if s[j] in record:
                while s[j] in record:
                    del record[s[i]]
                    i += 1
                    n -= 1
            
            record[s[j]] = j
            n += 1
            j += 1
            if n > max_length:
                max_length = n
        return max_length
# @lc code=end

