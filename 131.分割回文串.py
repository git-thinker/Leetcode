#
# @lc app=leetcode.cn id=131 lang=python3
#
# [131] 分割回文串
#

# @lc code=start
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        ans = {tuple(s)}

        # initially separate string into chars
        # so that each char is always symmetric (list)
        # scan list vertify if 2 / 3 continuous element constitue symmetric string
        # if yes, merge these element and store into ans
        # if already exists in ans then no need to recursive 
        # since this circumstance has already been processed
        # if not exists recursive processed new list
        
        def isSymmetric(s1:str, s2:str):
            if s2[::-1] == s1:
                return True
            else:
                return False

        def recursive(loopList: list):
            if len(loopList) == 1:
                return None
            else:
                # next is even char
                for i in range(len(loopList) - 1):
                    if isSymmetric(loopList[i], loopList[i+1]):
                        loopListcopy = loopList[:]
                        loopListcopy[i] = loopList[i] + loopList[i+1]
                        del loopListcopy[i+1]
                        length = len(ans)
                        ans.add(tuple(loopListcopy))
                        if length != len(ans):
                            recursive(loopListcopy)
                    if i > 0:
                        if isSymmetric(loopList[i-1], loopList[i+1]):
                            loopListcopy = loopList[:]
                            loopListcopy[i] = loopList[i-1] + loopListcopy[i] + loopList[i+1]
                            del loopListcopy[i+1]
                            del loopListcopy[i-1]
                            length = len(ans)
                            ans.add(tuple(loopListcopy))
                            if length != len(ans):
                                recursive(loopListcopy)

        recursive(list(s))
        return [list(i) for i in ans]

class Solution:
    def isSymmtric(self, lo, hi):
        while lo < hi:
            if self.string[lo] != self.string[hi]:
                return False
            lo += 1
            hi -= 1
        return True

    # set a flag to divid string into processed and to_be_processed
    # scan to_be_processed
    # once reach a point that makes processed - point symmetric
    # recursive process remainder

    def recursive(self, start):
        if start == len(self.string):
            self.ans.append(self.stack[:])
            return None
        else:
            for i in range(start, len(self.string)):
                if self.isSymmtric(start, i):
                    self.stack.append(self.string[start:i+1])
                    self.recursive(i+1)
                    self.stack.pop()

    def partition(self, s: str) -> List[List[str]]:
        self.string = s
        self.ans = []
        self.stack = []
        self.recursive(0)
        return self.ans
# @lc code=end

