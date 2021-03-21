/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        for(string& str: tokens){
            if(this->isNum(str)){
                numStack.push(this->getNum(str));
            }else{
                int i = numStack.top(); numStack.pop();
                int j = numStack.top(); numStack.pop();
                if(str == "+"){
                    numStack.push(j + i);
                }else if (str == "-"){
                    numStack.push(j - i);
                }else if (str == "*"){
                    numStack.push(j * i);
                }else if (str == "/"){
                    numStack.push(j / i);
                }
            }
        }
        return numStack.top();
    }

    bool isNum(string& numStr){
        return ('0' <= numStr.back() && numStr.back() <= '9');
    }

    int getNum(string& numStr){
        bool flag = false;
        int num = 0;
        if(numStr[0] == '-') flag = true;
        for(int i = 0; i < numStr.size(); i++){
            if('0' <= numStr[i] && numStr[i] <= '9'){
                num *= 10;
                num += flag ? -(numStr[i] - 48) : (numStr[i] - 48);
            }
        }
        return num;
    }
};
// @lc code=end

