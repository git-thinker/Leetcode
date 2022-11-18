/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                if(flag) return false;
                else if(i+1 != s.size() && s[i+1] == '0') flag = true;
            }
        }
        return true;
    }
};
// @lc code=end

