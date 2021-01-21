#
# @lc app=leetcode.cn id=938 lang=python3
#
# [938] 二叉搜索树的范围和
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        def recursive_sum(root):
            if root is None:
                return 0
            elif low <= root.val <= high:
                return root.val + recursive_sum(root.left) + recursive_sum(root.right)
            elif root.val < low:
                return recursive_sum(root.right)
            elif root.val > high:
                return recursive_sum(root.left)
        return recursive_sum(root)

# @lc code=end

