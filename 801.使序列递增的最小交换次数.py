#
# @lc app=leetcode.cn id=801 lang=python3
#
# [801] 使序列递增的最小交换次数
#
from typing import *
# @lc code=start
class Solution:
    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        keep = [0]
        change = [1]
        for i in range(1, len(nums1)):
            a, b = keep[-1], change[-1]
            ok_for_not_change = nums1[i - 1] < nums1[i] and nums2[i - 1] < nums2[i]
            ok_for_change = nums1[i - 1] < nums2[i] and nums2[i - 1] < nums1[i]
            if ok_for_not_change and not ok_for_change:
                keep.append(a)
                change.append(b+1)
            elif not ok_for_not_change and ok_for_change:
                # ok for change at i
                keep.append(b)
                change.append(a+1)
            else:
                keep.append(min(a,b))
                change.append(min(a, b)+1)
        return min((keep[-1], change[-1]))



# @lc code=end

