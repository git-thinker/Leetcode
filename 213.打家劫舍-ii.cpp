/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int ret;
        if(nums.size() < 4){
            ret = nums[0];
            for(auto& item: nums){
                if(item > ret) ret = item;
            }
        }else{
            vector<int> dp0 = {nums[0], max(nums[0], nums[1])};
            vector<int> dp1 = {nums[1], max(nums[1], nums[2])};
            for(int i = 2; i < nums.size() - 1; i++){
                dp0.push_back(max(dp0[i-2] + nums[i], dp0[i-1]));
                dp1.push_back(max(dp1[i-2] + nums[i+1], dp1[i-1]));
            }
            ret = dp0[0];
            for(int i = 0; i < dp0.size(); i++){
                if(dp0[i] > ret) ret = dp0[i];
                if(dp1[i] > ret) ret = dp1[i];
            }
        }
        return ret;
    }
};
// @lc code=end

