/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
        int ret = 0;
        int counter = 0;
        for(auto item: s){
            if(item == 'L') counter++;
            else counter--;
            if(counter == 0){
                ret++;
            }
        }
        return ret;
    }
};
// @lc code=end

