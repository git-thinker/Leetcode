#
# @lc app=leetcode.cn id=451 lang=python3
#
# [451] 根据字符出现频率排序
#

# @lc code=start
class Solution:
    def frequencySort(self, s: str) -> str:
        rst = ''
        counter = collections.Counter(s)
        heap = [(-freq, char) for char, freq in counter.items()]
        heapq.heapify(heap)
        
        while heap:
            freq, char = heapq.heappop(heap)
            rst += -freq * char

        return rst
        
# @lc code=end

