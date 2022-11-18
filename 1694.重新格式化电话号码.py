#
# @lc app=leetcode.cn id=1694 lang=python3
#
# [1694] 重新格式化电话号码
#

# @lc code=start
class Solution:
    def reformatNumber(self, number: str) -> str:
        number = number.replace('-', '').replace(' ', '')
        numbers = [number[i:i+3] for i in range(0, len(number), 3)]
        if len(numbers[-1]) == 1:
            tmp = numbers[-2] + numbers[-1]
            numbers.pop();numbers.pop()
            numbers.append(tmp[:2])
            numbers.append(tmp[2:])
        return '-'.join(numbers)
# @lc code=end

