#
# @lc app=leetcode.cn id=227 lang=python3
#
# [227] 基本计算器 II
#

# @lc code=start
class Solution:
    def calculate(self, s: str) -> int:
        num = 0
        oper = ''
        stack = []
        for i, char in enumerate(s):
            if char == ' ':
                pass
            elif '0' <= char <= '9':
                num *= 10
                num += int(char)
            if char in ('+', '-', '*', '/') or i == len(s)-1:
                if not oper:
                    oper = char
                    stack.append(num)
                    num = 0
                else:
                    if oper == '+':
                        stack.append(num)
                    elif oper == '-':
                        stack.append(-num)
                    elif oper == '*':
                        stack[-1] *= num
                    elif oper == '/':
                        stack[-1] /= num
                        stack[-1] = int(stack[-1])
                    oper = char
                    num = 0
        return sum(stack)


                    

# @lc code=end

