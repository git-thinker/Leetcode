#
# @lc app=leetcode.cn id=870 lang=python3
#
# [870] 优势洗牌
#
import collections
# @lc code=start
class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums = nums2[:]
        nums.sort()
        mapping = collections.defaultdict(list)
        rubbish = []
        i, j = 0, 0
        while i < len(nums1) and j < len(nums):
            if nums1[i] > nums[j]:
                mapping[nums[j]].append(nums1[i])
                j += 1
            else:
                rubbish.append(nums1[i])
            i += 1
        ret = []
        for item in nums2:
            if mapping[item]:
                ret.append(mapping[item].pop())
            elif rubbish:
                ret.append(rubbish.pop())
        return ret
# @lc code=end

