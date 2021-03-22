/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        for(int i = 0; i < 32; ++i){
            if((n & (n|1))&1) num++;
            n >>= 1;
        }
        return num;
    }
};
// @lc code=end

