/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int idx = 0;
        int this_jump_range = 0;
        int next_jump_range = 0;
        int jump = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(next_jump_range < nums[i] + i){
                next_jump_range = nums[i] + i;
            }
            if(this_jump_range == i){
                jump++;
                this_jump_range = next_jump_range;
                next_jump_range = 0;
            }
        }
        return jump;
    }
};
// @lc code=end

