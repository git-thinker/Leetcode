#
# @lc app=leetcode.cn id=896 lang=python3
#
# [896] 单调数列
#

# @lc code=start
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if len(A) < 3:
            return True
        # init with unknown status
        status = 0
        for i in range(1, len(A)):
            if A[i - 1] == A[i]:
                continue
            if not status:
                status = 1 if A[i-1] < A[i] else 2
            if status:
                if status == 1 and A[i-1] > A[i] or status == 2 and A[i-1] < A[i]:
                    return False
        return True
               
# @lc code=end

