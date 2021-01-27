#
# @lc app=leetcode.cn id=1128 lang=python3
#
# [1128] 等价多米诺骨牌对的数量
#

# @lc code=start
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        rst = 0
        hash_map = [0] * 100
        for (a,b) in dominoes:
            if a > b:
                a, b = b, a
            hash_map[a * 10 + b] += 1        
        for value in hash_map:
            if value > 1:
                rst += (value * (value - 1)) / 2
        return int(rst)

    # def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
    #     import math
    #     hash_map = collections.Counter()
    #     for item in dominoes:
    #         item = item[:]
    #         item = ''.join([str(i) for i in sorted(item)])
    #         if item not in hash_map:
    #             hash_map[item] = 1
    #         else:
    #             hash_map[item] += 1
    #     rst = 0
    #     for key, value in hash_map.items():
    #         if value != 1:
    #             rst += math.factorial(value)//(math.factorial(2)*math.factorial(value-2))
    #     return rst
# @lc code=end

