#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个正序数组的中位数
#

# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        # this solution does not meet O(log(m+n))
        # O(m+n) solution
        # merge with limited length

        temp = []
        m = len(nums1) + len(nums2)
        n = m // 2
        
        while len(temp) != n + 1 and (nums1 or nums2):
            if nums1 or nums2:
                if nums1 and not nums2:
                    temp.append(nums1.pop(0))
                elif not nums1 and nums2:
                    temp.append(nums2.pop(0))
                else:
                    if nums1[0] <= nums2[0]: 
                        temp.append(nums1.pop(0))
                    else:
                        temp.append(nums2.pop(0))
        
        return temp[-1] if m % 2 else (temp[-1] + temp[-2]) / 2

# @lc code=end

