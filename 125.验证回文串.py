#
# @lc app=leetcode.cn id=125 lang=python3
#
# [125] 验证回文串
#

# @lc code=start
class Solution:
    def isPalindrome(self, s: str) -> bool:
        def verify(char: str) -> bool:
            char = ord(char)
            if 65 <= char <= 90:
                return True
            if 97 <= char <= 122:
                return True
            if 48 <= char <= 57:
                return True
            return False

        if not s:
            return True
        else:
            i, j = 0, len(s) - 1
            s = s.lower()
            while i < j:
                if not verify(s[i]):
                    i += 1
                if not verify(s[j]):
                    j -= 1
                if verify(s[i]) and verify(s[j]):
                    if s[i] != s[j]:
                        return False
                    else:
                        i += 1
                        j -= 1
            return True

# @lc code=end

