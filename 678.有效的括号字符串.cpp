/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        int upper = 0;
        int lower = 0;
        for(auto item : s){
            if(item == '('){
                upper++;
                lower++;
            }else if(item == ')'){
                upper--;
                lower--;
            }else{
                upper++;
                lower--;
            }
            if(lower <= 0) lower = 0;
            if(upper < 0) return false;
        }
        if(lower <= 0 && 0 <= upper){
            return true;
        }else{
            return false;
        }
    }
};
// @lc code=end

