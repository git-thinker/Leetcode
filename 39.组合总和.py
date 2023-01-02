#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#

# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def recursive(stack, sum, ii):
            for i in range(ii, len(candidates)):
                sum += candidates[i]
                stack.append(candidates[i])
                if sum  == target:
                    ret.add(tuple(stack))
                if sum < target:
                    recursive(stack, sum, i)
                sum -= candidates[i]
                stack.pop()
                    
        ret = set()
        sum = 0
        stack = []
        recursive(stack, sum, 0)
        return [list(i) for i in ret]
# @lc code=end

