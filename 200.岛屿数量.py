#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
#

# @lc code=start
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        rst = 0
        def crack(i, j):
            if not (0 <= i < m and 0 <= j < n):
                return None
            elif grid[i][j] == '1':
                grid[i][j] = '0'
            else:
                return None
            crack(i + 1, j)
            crack(i - 1, j)
            crack(i, j + 1)
            crack(i, j - 1)            
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    rst += 1
                    crack(i, j)
        return rst

# @lc code=end

