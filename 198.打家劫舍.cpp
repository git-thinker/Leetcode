/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> value;
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        value.push_back(nums[0]);
        value.push_back(max(nums[0], nums[1]));
        for(int i = 2; i < nums.size(); ++i){
            value.push_back(max(nums[i]+value[i-2], value[i-1])); 
        }
        return value.back();
    }
};
// @lc code=end

