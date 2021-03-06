/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        vector<int> dynamicAns;
        for(int i = 0; i < nums.size(); ++i){
            dynamicAns.emplace_back(0);
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i] && dynamicAns[j] > dynamicAns.back()){
                    dynamicAns.back() = dynamicAns[j];
                }
            }
            dynamicAns.back()++;
            if(dynamicAns.back() > ans){
                ans = dynamicAns.back();
            }
        }
        return ans;
    }
};
// @lc code=end

