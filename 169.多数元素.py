#
# @lc app=leetcode.cn id=169 lang=python3
#
# [169] 多数元素
#

# @lc code=start
import collections
class Solution:
    # def majorityElement(self, nums: List[int]) -> int:
    #     counter = collections.Counter(nums)
    #     return counter.most_common(1)[0][0]

    def majorityElement(self, nums: List[int]) -> int:
        def recursive(i: int, j:int):
            if i == j:
                return nums[i]
            else:
                m = (i + j) // 2
                a = recursive(i, m)
                b = recursive(m + 1, j)
                countA, countB = 0, 0
                for k in range(i, j + 1):
                    if nums[k] == a:
                        countA += 1
                    elif nums[k] == b:
                        countB += 1
                if countA >= countB:
                    return a
                else:
                    return b
        return recursive(0, len(nums) - 1)


# @lc code=end

