/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include<queue>
using namespace std;
// @lc code=start
class MyStack {
public:
    // queue<int> q0;
    // queue<int> q1; 

    queue<int> q;
    MyStack() {

    }
    
    void push(int x){
        q.push(x);
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        int ret = q.front();
        q.pop();
        return ret;
    }
    int top(){
        return q.front();
    }
    bool empty(){
        return q.empty();
    }
    // void push(int x) {
    //     q1.push(x);
    //     while(!q0.empty()){
    //         q1.push(q0.front());
    //         q0.pop();
    //     }
    //     swap(q0, q1);
    // }
    
    // int pop() {
    //     int ret = this->top();
    //     q0.pop();
    //     return ret;
    // }
    
    // int top() {
    //     return q0.front();
    // }
    
    // bool empty() {
    //     return q0.empty();
    // }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

