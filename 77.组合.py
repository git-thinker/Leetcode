#
# @lc app=leetcode.cn id=77 lang=python3
#
# [77] 组合
#

# @lc code=start
class Solution:
    # def combine(self, n: int, k: int) -> List[List[int]]:
    #     nums = [i for i in range(1, n+1)]
    #     rst = []
    #     tmp_rst = [[]]
    #     for item in nums:
    #         length = len(tmp_rst)
    #         i = 0
    #         while i < length:
    #             tmp = tmp_rst[i] + [item]
    #             if len(tmp) == k:
    #                 rst.append(tmp)
    #             else:
    #                 tmp_rst.append(tmp)    
    #             i += 1    
    #     return rst
        
    def combine(self, n: int, k: int) -> List[List[int]]:
        rst = []
        def recursive(tmp_rst, index):
            if len(tmp_rst) == k:
                rst.append(tmp_rst)
                return None
            if tmp_rst:
                lower = tmp_rst[-1] + 1
                if lower + index - 1 > n:
                    return None
            else:
                lower = 1
            for i in range(lower, n + 1):
                recursive(tmp_rst + [i], index - 1)
        recursive([], k)
        return rst

# @lc code=end

