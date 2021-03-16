#
# @lc app=leetcode.cn id=224 lang=python3
#
# [224] 基本计算器
#

# @lc code=start
class Solution:
    def calculate(self, s: str) -> int:
        s = s.strip() + ' '
        operator = ' '
        numFlag = False
        num = 0
        stack = [0]
        for i, char in enumerate(s):
            if char == ' ':
                pass
            elif '0' <= char <= '9':
                numFlag = True
                num *= 10
                num += int(char)
            else:
                if char == '(':
                    stack.append((operator,))
                    numFlag = False
                    num = 0
                    operator = ' '
                elif char == ')':
                    if operator == "+":
                        num += stack.pop()
                    elif operator == '-':
                        num = stack.pop() - num
                    operator, = stack.pop()
                elif operator == ' ':
                    # no action in need
                    operator = char
                    stack.append(num)
                    num = 0
                    numFlag = False
                elif char in ('+', '-'):
                    if not numFlag:
                        if operator == "+":
                            operator = char
                        elif operator == '-' and char =='-':
                            operator = '+'
                    else:
                        if operator == "+":
                            num += stack.pop()
                        elif operator == '-':
                            num = stack.pop() - num
                        operator = ' '
                        stack.append(num)
                        num = 0
                        numFlag = False
                    operator = char
                
            if i == len(s)-1:
                if operator != ' ':
                    if operator == "+":
                        num += stack.pop()
                    elif operator == '-':
                        num = stack.pop() - num
                    operator = ' '
                    stack.append(num)
                    num = 0
                    numFlag = False
                elif num != 0:
                    stack.append(num)
        return stack[-1]

# @lc code=end

