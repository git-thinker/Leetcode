#
# @lc app=leetcode.cn id=547 lang=python3
#
# [547] 省份数量
#

# @lc code=start
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def find(i):
            while parent[i] != i:
                i = parent[i]
            return i
        def union(i, j):
            parent[find(i)] = find(j)
            return None
        n = len(isConnected)
        parent = [i for i in range(n)]
        for i in range(n):
            for j in range(i):
                if isConnected[i][j]:
                    union(i, j)
        rst = sum(parent[i] == i for i in range(n))
        return rst
# @lc code=end

