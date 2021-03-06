/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include<stack>
using namespace std;
class MyQueue {
public:
stack<int> stackMain;
stack<int> stackAssistant;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!stackMain.empty()){
            stackAssistant.push(stackMain.top());
            stackMain.pop();
        }
        stackMain.push(x);
        while(!stackAssistant.empty()){
            stackMain.push(stackAssistant.top());
            stackAssistant.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = stackMain.top();
        stackMain.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return stackMain.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stackMain.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

