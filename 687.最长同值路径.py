#
# @lc app=leetcode.cn id=687 lang=python3
#
# [687] 最长同值路径
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        length = 0
        def recursive(node):
            nonlocal length
            if node is None:
                return -1, -1
            else:
                left_val, left_len = recursive(node.left)
                right_val, right_len = recursive(node.right)
                if left_val == right_val == node.val:
                    if left_len + right_len + 2 > length:
                        length = left_len + right_len + 2
                    if left_len > right_len:
                        tmp = left_len + 1
                    else:
                        tmp = right_len + 1
                else:
                    if left_val == node.val:
                        tmp = left_len + 1
                    elif right_val == node.val:
                        tmp = right_len + 1
                    else:
                        tmp = 0
                if tmp > length:
                    length = tmp
                return node.val, tmp
        recursive(root)
        return length
# @lc code=end

