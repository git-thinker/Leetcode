#
# @lc app=leetcode.cn id=210 lang=python3
#
# [210] 课程表 II
#

# @lc code=start
import collections
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        inDegree = [0] * numCourses
        edges = collections.defaultdict(list)
        queue = collections.deque()
        rst = []
        for item in prerequisites:
            inDegree[item[0]] += 1
            edges[item[1]].append(item[0])
        for i, item in enumerate(inDegree):
            if not item:
                queue.append(i)
        while len(queue):
            tmp = queue.popleft()
            rst.append(tmp)
            for i in edges[tmp]:
                inDegree[i] -= 1
                if not inDegree[i]:
                    queue.append(i)
        if len(rst) == numCourses:
            return rst
        else:
            return []




# @lc code=end

