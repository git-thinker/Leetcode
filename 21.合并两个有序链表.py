#
# @lc app=leetcode.cn id=21 lang=python3
#
# [21] 合并两个有序链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode()  
        cursor = head
        while l1 or l2:
            if l1 and l2:
                if l1.val < l2.val:
                    cursor.next = ListNode(l1.val)
                    l1 = l1.next
                else:
                    cursor.next = ListNode(l2.val)
                    l2 = l2.next
            elif l1:
                cursor.next = ListNode(l1.val)
                l1 = l1.next
            elif l2:
                cursor.next = ListNode(l2.val)
                l2 = l2.next
            cursor = cursor.next
        return head.next
            
# @lc code=end

