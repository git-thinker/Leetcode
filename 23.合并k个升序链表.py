#
# @lc app=leetcode.cn id=23 lang=python3
#
# [23] 合并K个升序链表
#

from ds import *
import heapq
List = list
# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        heap_list = []
        for item in lists:
            while item:
                heapq.heappush(heap_list, item.val)
                item = item.next
        cursor = root = ListNode(0)
        while heap_list:
            cursor.next = ListNode(heapq.heappop(heap_list))
            cursor = cursor.next
        return root.next
# @lc code=end

