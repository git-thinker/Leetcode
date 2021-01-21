#
# @lc app=leetcode.cn id=692 lang=python3
#
# [692] 前K个高频单词
#

# @lc code=start
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        counting_map = collections.Counter(words)
        mapping = {}
        index = []
        rst = []
        for key, value in counting_map.items():
            if value in mapping:
                mapping[value].append(key)
                mapping[value].sort()
            else:
                mapping[value] = [key]
            if -value not in index:
                heapq.heappush(index, -value)
        while len(rst) != k:
            if len(rst) < k:
                rst.extend(mapping[-heapq.heappop(index)])
            else:
                rst.pop()
        return rst
        
# @lc code=end

