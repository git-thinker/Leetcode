/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(i <= reachable){
                reachable = max(reachable, i + nums[i]);
            }else{
                break;
            }
        }
        return reachable >= nums.size()-1;
    }
};
// @lc code=end

