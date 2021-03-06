#
# @lc app=leetcode.cn id=510 lang=python3
#
# [510] 二叉搜索树中的中序后继 II
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Node':
        if node.right:
            node = node.right
            while node.left:
                node = node.left
        else:
            while node.parent and node == node.parent.right:
                node = node.parent
            node = node.parent
        return node
# @lc code=end

