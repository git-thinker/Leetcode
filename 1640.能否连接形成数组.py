#
# @lc app=leetcode.cn id=1640 lang=python3
#
# [1640] 能否连接形成数组
#
from typing import *
# @lc code=start
class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        mySet = {tuple(i) for i in pieces}
        i = 0
        while i < len(arr):
            flag = True
            for j in range(i + 1, len(arr) + 1):
                if tuple(list(arr[i:j])) in mySet:
                    flag = False
                    break
            if flag:
                return False
            i = j
        return True
# @lc code=end

