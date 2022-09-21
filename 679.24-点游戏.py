#
# @lc app=leetcode.cn id=679 lang=python3
#
# [679] 24 点游戏
#

# @lc code=start
class Solution:
    def judgePoint24(self, cards) -> bool:
        queue =[]
        def dfs(queue, ok):
            if ok == 0:
                if check(queue):
                    return True
                return False
            for i in range(4):
                if (ok >> i) & 1:
                    queue.append(cards[i])
                    if dfs(queue, ok & ~(1 << i)):
                        return True
                    queue.pop()
            return False
        def check(queue):
            operator = {'+', '-', '*', '/'}
            for oa in operator:
                for ob in operator:
                    for oc in operator:
                        try:
                            if abs(eval("((%d%s%d)%s%d)%s%d" % (queue[0], oa, queue[1], ob, queue[2], oc, queue[3])) - 24) < 1e-5:
                                return True
                        except:
                            pass
                        try:
                            if abs(eval("(%d%s(%d%s%d))%s%d" % (queue[0], oa, queue[1], ob, queue[2], oc, queue[3])) - 24) < 1e-5:
                                return True
                        except:
                            pass
                        try:
                            if abs(eval("%d%s((%d%s%d)%s%d)" % (queue[0], oa, queue[1], ob, queue[2], oc, queue[3])) - 24) < 1e-5:
                                return True
                        except:
                            pass
                        try:
                            if abs(eval("%d%s(%d%s(%d%s%d))" % (queue[0], oa, queue[1], ob, queue[2], oc, queue[3])) - 24) < 1e-5:
                                return True
                        except:
                            pass
                        try:
                            if abs(eval("(%d%s%d)%s(%d%s%d)" % (queue[0], oa, queue[1], ob, queue[2], oc, queue[3])) - 24) < 1e-5:
                                return True
                        except:
                            pass
            return False
        return dfs(queue, 15)
# @lc code=end

