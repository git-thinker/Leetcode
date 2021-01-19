#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        cf = 0
        val = 0
        head = ListNode()
        cursor = head
        while l1 or l2 or cf:
            val = cf 
            val += l1.val if l1 else 0
            val += l2.val if l2 else 0
            cf = val // 10
            val %= 10
            l1 = l1.next if l1 else l1
            l2 = l2.next if l2 else l2
            cursor.next = ListNode(val)
            cursor = cursor.next
        return head.next
            



# @lc code=end

