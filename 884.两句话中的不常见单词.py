#
# @lc app=leetcode.cn id=884 lang=python3
#
# [884] 两句话中的不常见单词
#
import collections
# @lc code=start
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        counter0 = collections.defaultdict(int)
        counter1 = collections.defaultdict(int)
        
        for each in s1.split():
            counter0[each] += 1

        for each in s2.split():
            counter1[each] += 1

        ans = []
        for i, j in counter0.items():
            if j == 1 and i not in counter1:
                ans.append(i)

        for i, j in counter1.items():
            if j == 1 and i not in counter0:
                ans.append(i)        

        return ans
# @lc code=end

