#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#

# @lc code=start
List = list
class Solution:
    # def findKthLargest(self, nums: List[int], k: int) -> int:
    #     sorting solution
    #     nums.sort()
    #     return nums[-k]

    # def findKthLargest(self, nums: List[int], k: int) -> int:
    #     import heapq
    #     nums = [-i for i in nums]
    #     heapq.heapify(nums)
    #     for i in range(k):
    #         rst = -heapq.heappop(nums)
    #     return rst
    
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def recursive(i: int, j: int):
            if i >= j:
                return None
            pivot = nums[i]
            cursor_i, cursor_j = i + 1, j
            while cursor_i <= cursor_j:
                if nums[cursor_i] < pivot and nums[cursor_j] >= pivot:
                    nums[cursor_i], nums[cursor_j] = nums[cursor_j], nums[cursor_i]
                    cursor_i += 1
                    cursor_j -= 1
                else:
                    if nums[cursor_i] >= pivot:
                        cursor_i += 1
                    if nums[cursor_j] < pivot:
                        cursor_j -= 1
            nums[i], nums[cursor_j] = nums[cursor_j], nums[i]
            if cursor_j == k - 1:
                return None
            recursive(i, cursor_j - 1)
            recursive(cursor_j + 1, j)
        recursive(0, len(nums) - 1)
        return nums[k-1]
# @lc code=end

