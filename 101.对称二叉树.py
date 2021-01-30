#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import collections
class Solution:
    # def isSymmetric(self, root: TreeNode) -> bool:
    #     if root is None:
    #         return True
    #     def recursive(p: TreeNode, q: TreeNode):
    #         if (p is None) ^ (q is None):
    #             return False
    #         if (p is None) and (q is None):
    #             return True
    #         return p.val == q.val and recursive(p.left, q.right) and recursive(p.right, q.left)
    #     return recursive(root.left, root.right)


    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        queue = collections.deque()
        queue.append(root.left)
        queue.append(root.right)

        while len(queue):
            tmp1 = queue.popleft()
            tmp2 = queue.popleft()
            if (tmp1 is None) ^ (tmp2 is None):
                return False
            if tmp1 == tmp2 == None:
                continue
            if tmp1.val != tmp2.val:
                return False
            else:
                queue.append(tmp1.left)
                queue.append(tmp2.right)
                queue.append(tmp2.left)
                queue.append(tmp1.right)
        return True
        
            

        
# @lc code=end

