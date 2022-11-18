#
# @lc app=leetcode.cn id=788 lang=python3
#
# [788] 旋转数字
#

# @lc code=start
class Solution:
    def rotatedDigits(self, n: int) -> int:
        positives = {2, 5, 6, 9}
        negatives = {3, 4, 7}
        neutrals = {0, 1, 8}

        def check(num: int):
            flag = False
            for i in str(num):
                i = int(i)
                if i in negatives:
                    return False
                if i in positives:
                    flag = True
            return flag
        
        ret = 0
        for i in range(1, n+1):
            if check(i):
                ret += 1
        return ret


# @lc code=end

