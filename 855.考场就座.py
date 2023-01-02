#
# @lc app=leetcode.cn id=855 lang=python3
#
# [855] 考场就座
#

# @lc code=start
class ExamRoom:

    def __init__(self, n: int):
        self.n = n
        self.log = []

    def seat(self) -> int:
        if len(self.log) == 0:
            self.log.append(0)
            return 0
        else:
            basic_length = (self.log[0] - 0)
            idx = 0
            insert_idx = 0
            for i in range(1, len(self.log)):
                if basic_length < (self.log[i] - self.log[i-1]) // 2:
                    basic_length = (self.log[i] - self.log[i-1]) // 2
                    idx = (self.log[i] + self.log[i-1]) // 2
                    insert_idx = i
            if basic_length < (self.n-1 - self.log[-1]):
                basic_length = (self.n-1 - self.log[-1])
                idx = self.n-1
                insert_idx = len(self.log)
            self.log.insert(insert_idx, idx)
            return idx

    def leave(self, p: int) -> None:
        for i in range(len(self.log)):
            if self.log[i] == p:
                del self.log[i]
                return None


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)
# @lc code=end

