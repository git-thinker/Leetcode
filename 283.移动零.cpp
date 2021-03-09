/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size()){
            if(nums[j]){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        for(i; i < nums.size(); i++) nums[i] = 0;
    }
};
// @lc code=end

