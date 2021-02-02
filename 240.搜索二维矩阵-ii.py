#
# @lc app=leetcode.cn id=240 lang=python3
#
# [240] 搜索二维矩阵 II
#

# @lc code=start
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __add__(self, p):
        return Point(self.x + p.x, self.y + p.y)
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def recursive(lower:Point, higher:Point):
            if not(0<=lower.x<m and 0<=lower.y<n and 0<=higher.x<m and 0<=higher.y<n and lower.x<=higher.x and lower.y<=higher.y):
                return False
            if lower == higher:
                if matrix[lower.x][lower.y] == target:
                    return True
                else:
                    return False
            i=0
            flag = False
            for i in range(min(higher.x - lower.x, higher.y - lower.y) + 1):
                if matrix[lower.x+i][lower.y+i] == target:
                    return True
                elif matrix[lower.x+i][lower.y+i] > target:
                    break
            else:
                return recursive(lower+Point(1,1), higher) or recursive(lower+Point(1,0), Point(higher.x,lower.y)) or recursive(lower+Point(0,1), Point(lower.x, higher.y))
            return (recursive(lower+Point(i,0),Point(higher.x, lower.y+i-1)) or recursive(lower+Point(0,i),Point(lower.x+i-1, higher.y)))
        m = len(matrix)
        n = len(matrix[0])
        return recursive(Point(0, 0), Point(m-1, n-1))
#  @lc code=end

