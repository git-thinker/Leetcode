#
# @lc app=leetcode.cn id=783 lang=python3
#
# [783] 二叉搜索树节点最小距离
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        queue = []
        def recursive(root):
            if root is None:
                return None
            else:
                recursive(root.left)
                queue.append(root.val)
                recursive(root.right)
        recursive(root)
        rst = min([queue[i] - queue[i-1] for i in range(1, len(queue))])
        return rst

    # def minDiffInBST(self, root: TreeNode) -> int:
    #     rst = float('inf')
    #     pre = -float('inf')
    #     def recursive(root):
    #         nonlocal rst, pre
    #         if root is None:
    #             return None
    #         else:
    #             recursive(root.left)
    #             if root.val - pre < rst:
    #                 rst = root.val - pre
    #             pre = root.val
    #             recursive(root.right)
    #     recursive(root)
    #     return rst
# @lc code=end

