#
# @lc app=leetcode.cn id=74 lang=python3
#
# [74] 搜索二维矩阵
#

# @lc code=start
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        length = len(matrix) * len(matrix[0])
        i, j = 0, length
        while i < j:
            m = (i + j) // 2
            x = m // len(matrix[0])
            y = m % len(matrix[0])
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] < target:
                i = m + 1
            else:
                j = m
        return False
# @lc code=end

