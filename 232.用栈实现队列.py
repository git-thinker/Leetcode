#
# @lc app=leetcode.cn id=232 lang=python3
#
# [232] 用栈实现队列
#

# @lc code=start
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.inStack = []
        self.outStack = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.inStack.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        ans = self.peek()
        self.outStack.pop()
        return ans


    def peek(self) -> int:
        """
        Get the front element.
        """
        if not self.outStack:
            self.inStack2outStack()
        return self.outStack[-1]


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not bool(len(self.inStack) or len(self.outStack))

    def inStack2outStack(self) -> None:
        while self.inStack:
            self.outStack.append(self.inStack.pop())



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
# @lc code=end

