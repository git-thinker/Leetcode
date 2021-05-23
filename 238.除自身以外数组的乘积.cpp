/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret = vector<int>(nums.size(), 1);
        int tmp;

        tmp = 1;
        for(int i = 0; i < nums.size()-1; i++){
            tmp *= nums[i];
            ret[i+1] *= tmp;
        }

        tmp = 1;
        for(int i = nums.size() - 1; i > 0;  i--){
            tmp *= nums[i];
            ret[i-1] *= tmp;
        }

        return ret;
    }
};
// @lc code=end

