/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include<vector>
#include<map>
using namespace std;
// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == -2147483648 && divisor == -1) return 2147483647;
        if(dividend == 0) return 0;
        bool neg = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        if(dividend > 0) dividend = -dividend;
        if(divisor > 0) divisor = -divisor;
        vector<pair<int, int>> base={{-1, divisor}};
        while(base.back().second >= -1073741824){
            base.push_back({base.back().first+base.back().first,base.back().second+base.back().second});
        }
        long ret = 0;
        for(int i = base.size()-1; i >= 0; i--){
            if(base[i].second >= dividend){
                dividend -= base[i].second;
                ret += base[i].first;
            }
        }
        return neg ? ret : -ret;
    }
};
// @lc code=end

