#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        pairing = {
                   ')' : '(',
                   '}' : '{',
                   ']' : '[',
        }

        vaild = [')', '(', '}', '{', ']', '[', ' ']

        for item in s:
            if item not in vaild:
                return False
            else:
                if item == ' ':
                    continue
                elif item not in pairing:
                    stack.append(item)
                elif item in pairing:
                    if not stack:
                        return False
                    else:
                        if pairing[item] != stack.pop():
                            return False
        
        if stack:
            return False
        else:
            return True

# @lc code=end

