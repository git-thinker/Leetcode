/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int counter = 0;
        int ret = 0;
        for(auto c: s){
            if(c == '('){
                counter++;
            }else{
                if(counter){
                    counter--;
                }else{
                    ret++;
                }
            }
        }
        if(counter) ret += counter;
        return ret;
    }
};
// @lc code=end

