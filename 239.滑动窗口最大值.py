#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#

# @lc code=start
import heapq
import collections
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        heap_list = []
        ret = []
        need_pop = collections.defaultdict(int)
        for _ in range(k):
            heapq.heappush(heap_list, -nums[_])
        ret.append(-heap_list[0])

        for i in range(k, len(nums)):
            heapq.heappush(heap_list, -nums[i])
            need_pop[-nums[i-k]] += 1
            while need_pop[heap_list[0]]:
                need_pop[heap_list[0]] -= 1
                heapq.heappop(heap_list)
            ret.append(-heap_list[0])
        return ret


# @lc code=end

