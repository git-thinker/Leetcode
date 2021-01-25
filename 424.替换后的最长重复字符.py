#
# @lc app=leetcode.cn id=424 lang=python3
#
# [424] 替换后的最长重复字符
#

# @lc code=start
from collections import Counter
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        def vertify(i, j):
            if (j - i) - counter.most_common(1)[0][1] <= k:
                return True
            else:
                return False
        def update(char, flag):
            if flag:
                if char in counter:
                    counter[char] += 1
                else:
                    counter[char] = 1
            else:
                counter[char] -= 1
        if not s:
            return 0
        counter = Counter(s[0])
        i, j = 0, 1
        while j < len(s):
            update(s[j], True)
            j += 1
            if not vertify(i, j):
                update(s[i], False)
                i += 1
        return j - i

# @lc code=end

