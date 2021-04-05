/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int clumsy(int N) {
        stack<int> myStack;
        int i = 0;
        int num;
        while(N){
            num = N;
            if(!myStack.empty()){
                switch(i % 4){
                    case 0:
                        num = -num;
                        break;
                    case 1:
                        num *= myStack.top();
                        myStack.pop();
                        break;
                    case 2:
                        num = myStack.top() / num;
                        myStack.pop();
                        break;
                    case 3:
                        break;
                }
            }
            myStack.push(num);
            i++;
            N--;
        }
        while(!myStack.empty()){
            N += myStack.top();
            myStack.pop();
        }
        return N;
    }
};
// @lc code=end

