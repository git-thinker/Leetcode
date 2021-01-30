#
# @lc app=leetcode.cn id=559 lang=python3
#
# [559] N 叉树的最大深度
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
import queue
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        layer = 0
        q = []
        q.append(root)
        q.append(None)
        while 1:
            tmp = q.pop(0)
            if tmp is None:
                layer += 1
                if not q:
                    break
                else:
                    q.append(None)
            else:
                for item in tmp.children:
                    q.append(item)
        return layer

    # def maxDepth(self, root: 'Node') -> int:
    #     if not root: return 0
    #     depth=1
    #     queue=[(root,depth)]
    #     while queue:
    #         root,depth=queue.pop(0)
    #         if root.children:
    #             for node in root.children: 
    #                 queue.append((node,depth+1))
    #     return depth

        
# @lc code=end

