#
# @lc app=leetcode.cn id=2133 lang=python3
#
# [2133] 检查是否每一行每一列都包含全部整数
#

from typing import List
# @lc code=start

import numpy as np
class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        matrix = np.array(matrix)
        n = len(matrix)
        s = (1 + n) * n / 2
        for item in np.concatenate((matrix, matrix.T)):
            if not(len(item) == len(set(item)) and item.sum() == s):
                return False
        return True

# @lc code=end

