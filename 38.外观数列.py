#
# @lc app=leetcode.cn id=38 lang=python3
#
# [38] 外观数列
#

# @lc code=start
class Solution:
    def countAndSay(self, n: int) -> str:
        ans = "1"
        n -= 1
        while n:
            answer = ""
            count = 1
            char = ans[0]
            for i in range(1, len(ans)):
                if char != ans[i]:
                    answer += str(count) + char
                    count = 1
                    char = ans[i]
                else:
                    count += 1
            answer += str(count) + char
            ans = answer
            n -= 1
        return ans
# @lc code=end

