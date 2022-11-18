#
# @lc app=leetcode.cn id=817 lang=python3
#
# [817] 链表组件
#
from typing import *
from ds import *
# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        nums_set = set(nums)
        ret = 0
        flag = False
        while head is not None:
            if head.val in nums_set:
                flag = True
            elif flag:
                ret += 1
                flag = False
            head = head.next
        if flag:
            ret += 1
        return ret
# @lc code=end

