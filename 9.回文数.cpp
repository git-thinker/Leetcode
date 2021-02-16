/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include<stack>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        stack<int> myStack;
        if(x < 0) return false;
        if(x < 10) return true;
        int n = 0;
        int tmp = x;
        bool odd = true;
        while(tmp){
            n++;
            tmp /= 10;
        }
        odd = n % 2;
        for(int i = 0; i < n; i++){
            if(i < n / 2){
                myStack.push(x%10);
                x /= 10;
            }else if(odd && i == n / 2){
                x /= 10;
                continue;
            }else{
                if(myStack.top() != x%10) return false;
                x /= 10;
                myStack.pop();
            }
        }
    return true;
    }
};
// @lc code=end

