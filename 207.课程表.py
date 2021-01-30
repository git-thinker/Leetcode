#
# @lc app=leetcode.cn id=207 lang=python3
#
# [207] 课程表
#

# @lc code=start
List = list
import collections
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        rst = 0
        inDegree = [0 for i in range(numCourses)]
        edges = collections.defaultdict(lambda:[])
        # key:本课程 value:后继课程
        for each in prerequisites:
            edges[each[1]].append(each[0])
            inDegree[each[0]] += 1
        queue = collections.deque()
        for i, each in enumerate(inDegree):
            if not each:
                queue.append(i)
        while len(queue):
            rst += 1
            tmp = queue.popleft()
            for each in edges[tmp]:
                inDegree[each] -= 1
                if not inDegree[each]:
                    queue.append(each)
        return rst == numCourses
# @lc code=end

