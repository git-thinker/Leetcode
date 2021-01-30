#
# @lc app=leetcode.cn id=100 lang=python3
#
# [100] 相同的树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def comp(pp: TreeNode, pq: TreeNode):
            if (pp is None) ^ (pq is None):
                return False
            if pp is None and pq is None:
                return True
            if pp.val == pq.val:
                if (not ((pp.left is None) ^ (pq.left is None))) and not (((pp.right is None) ^ (pq.right is None))):
                    return True
            return False

        stackA = [p]
        stackB = [q]
        try:
            while stackA and stackB:
                pa, pb = stackA.pop(), stackB.pop()
                if not comp(pa, pb):
                    return False
                if pa is not None and pb is not None:
                    if pa.left:
                        stackA.append(pa.left)
                    if pa.right:
                        stackA.append(pa.right)
                    if pb.left:
                        stackB.append(pb.left)
                    if pb.right:
                        stackB.append(pb.right)
        except:
            return False
        return True
                    

# @lc code=end

