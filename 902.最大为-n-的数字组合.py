#

# @lc app=leetcode.cn id=902 lang=python3
#
# [902] 最大为 N 的数字组合
#
from typing import *
# @lc code=start
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        # a hash set for digits
        mySet = {int(i) for i in digits}

        # how many valid number befor #i
        table = []
        tmp = 0
        for i in range(10):
            table.append(tmp)
            if i in mySet:
                tmp += 1
        
        ret = 0

        # all number with length < len(n) should be valid
        all_len = len(str(n)) - 1

        ret += sum([len(mySet) ** (i+1) for i in range(all_len)])
        # those with length == len(n)

        # all valid before at spot i
        # restricted valid at spot i (all spot matched)
        tmp0, tmp1 = table[int(str(n)[0])], int(str(n)[0]) in mySet
        for i, item in enumerate(str(n)):
            if i != 0:
                item = int(item)
                tmp0 = tmp0 * len(mySet) + tmp1 * table[item]
                tmp1 *= item in mySet
        ret += tmp0 + tmp1
        return ret
# @lc code=end

