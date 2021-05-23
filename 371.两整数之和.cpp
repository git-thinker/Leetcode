/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        unsigned ret = 0;
        bool a_bit, b_bit, s_bit, c_bit = 0;
        for(int i = 0; i < 32; i++){
            a_bit = (bool) (a & (0x1 << i));
            b_bit = (bool) (b & (0x1 << i));
            s_bit = a_bit ^ b_bit ^ c_bit;
            c_bit = (a_bit & b_bit) | (c_bit & (a_bit | b_bit));
            ret |= ((int)s_bit) << i;
        }
        return ret;
    }
};
// @lc code=end

