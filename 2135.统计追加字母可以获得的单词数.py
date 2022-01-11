#
# @lc app=leetcode.cn id=2135 lang=python3
#
# [2135] 统计追加字母可以获得的单词数
#

from typing import List
import collections

# @lc code=start
class Solution:
    # this will TLE

    # def isConvertable(self, startWordsCounter, targetWordsCounter) -> bool:
    #     # principles
    #     # 1. those in startWordsCounter == counterparts in targetWordsCounter
    #     # 2. startWordsCounter != targetWordsCounter
    #     # 3. those in targetWordsCounter and not in startWordsCounter should be 1
    #     if startWordsCounter == targetWordsCounter or len(targetWordsCounter) - len(startWordsCounter) != 1:
    #         return False


    #     targetWordsCounter_ = targetWordsCounter.copy()
    #     for key in startWordsCounter.keys():
    #         targetWordsCounter_[key] -= startWordsCounter[key]
    #     for key in targetWordsCounter_.keys():
    #         if key in startWordsCounter and targetWordsCounter_[key]:
    #             return False
    #         if key not in startWordsCounter and targetWordsCounter_[key] != 1:
    #             return False
    #     return True



    # def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
    #     startWordsCounterList = [collections.Counter(i) for i in startWords]
    #     targetWordsCounterList = [collections.Counter(i) for i in targetWords]
    #     cnt = 0

    #     for i in targetWordsCounterList:
    #         for j in startWordsCounterList:
    #             if self.isConvertable(j, i):
    #                 cnt += 1
    #                 break

    #     return cnt

    def word2int(self, word: str) -> int:
        ret = 0
        for item in word:
            ret = ret | (1 << (ord(item) - ord('a')))
        return ret

    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        maskSet = set()
        cnt = 0

        for item in startWords:
            mask = self.word2int(item)
            for i in range(26):
                if ((mask >> i) & 1) == 0:
                    maskSet.add(mask | (1 << i))
        
        for item in targetWords:
            if self.word2int(item) in maskSet:
                cnt += 1

        return cnt


# @lc code=end

Solution().wordCount(["ant","act","tack"], ["tack","act","acti"])