#
# @lc app=leetcode.cn id=395 lang=python3
#
# [395] 至少有K个重复字符的最长子串
#

# @lc code=start
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        def recursive(s):
            # spliting
            counter = collections.Counter(s)
            spliting = []
            for key, value in counter.items():
                if 0 < value < k:
                    spliting.append(key)
            if not spliting:
                return len(s)
            spliting = set(spliting)
            i, j = 0, 0
            splited = []
            for j in range(len(s)):
                if s[j] in spliting:
                    if i != j:
                        splited.append(s[i:j])
                    i = j + 1
            if s[i:j+1]:
                splited.append(s[i:j+1])
            return max([recursive(i) for i in splited] + [0])
        return recursive(s)
# @lc code=end

