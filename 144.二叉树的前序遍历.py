#
# @lc app=leetcode.cn id=144 lang=python3
#
# [144] 二叉树的前序遍历
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        stack = []
        ans = []
        while root is not None or stack:
            if root is not None:
                ans.append(root.val)
                if root.right is not None:
                    stack.append(root.right)
                root = root.left
            else:
                root = stack.pop()
        return ans
# @lc code=end

