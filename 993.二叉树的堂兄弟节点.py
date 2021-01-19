#
# @lc app=leetcode.cn id=993 lang=python3
#
# [993] 二叉树的堂兄弟节点
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        # iterative DFS to store all nodes depth and parents
        # None as layer separation
        
        queue = []
        depth = {}
        parent = {}
        layer = -1

        queue.append(None)
        queue.append(root)
        while len(queue)!=1:
            cursor = queue.pop(0)
            if cursor is None:
                # add separation when last layer is done
                layer += 1
                queue.append(None)
                continue
            depth[cursor.val] = layer
            if cursor.left:
                parent[cursor.left.val] = cursor.val
                queue.append(cursor.left)
            if cursor.right:
                parent[cursor.right.val] = cursor.val
                queue.append(cursor.right)
            if x in depth and y in depth:
                break
            
        return (depth[x] == depth[y]) and (parent[x] != parent[y])
            
# @lc code=end

