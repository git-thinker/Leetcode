#
# @lc app=leetcode.cn id=690 lang=python3
#
# [690] 员工的重要性
#

# @lc code=start
"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    # def getImportance(self, employees: List['Employee'], id: int) -> int:
    #     importance = {e.id: e.importance for e in employees}
    #     subordinates = {e.id: e.subordinates for e in employees}
    #     self.rst = 0
    #     def dfs(id: int):
    #         self.rst += importance[id]
    #         for e in subordinates[id]:
    #             dfs(e)
    #     dfs(id)
    #     return self.rst

    def getImportance(self, employees: List['Employee'], id: int) -> int:
        importance = {e.id: e.importance for e in employees}
        subordinates = {e.id: e.subordinates for e in employees}
        rst = 0
        stack = [id]
        while stack:
            tmp = stack.pop()
            rst += importance[tmp]
            for e in subordinates[tmp]:
                stack.append(e)
        return rst
                    

            
# @lc code=end

