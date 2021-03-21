/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include<vector>
#include<map>
using namespace std;
class MinStack {
public:
    vector<pair<int, int>> myStack;
    int min;
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        if(myStack.empty()) myStack.push_back(pair<int, int>(val, val));
        else myStack.push_back(pair<int, int>(val, val < myStack.back().second ? val : myStack.back().second));
    }
    
    void pop() {
        myStack.pop_back();
    }
    
    int top() {
        return myStack.back().first;
    }
    
    int getMin() {
        return myStack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

