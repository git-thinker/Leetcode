#
# @lc app=leetcode.cn id=1736 lang=python3
#
# [1736] 替换隐藏数字得到的最晚时间
#

# @lc code=start
import re
class Solution:
    def maximumTime(self, time: str) -> str:
        while ret := re.search(re.compile('[?]'), time):
            if ret.span()[0] == 0:
                if ord('4') <= ord(time[1]) <= ord('9'):
                    time = '1' + time[1:]
                else:
                    time = '2' + time[1:]

            elif ret.span()[0] == 1:
                if time[0] == '2':
                    time = time[0] + '3' + time[2:]
                else:
                    time = time[0] + '9' + time[2:]
            elif ret.span()[0] == 3:
                time = time[:3] + '5' + time[4:]
            elif ret.span()[0] == 4:
                time = time[:4] + '9'
        return time
# @lc code=end

