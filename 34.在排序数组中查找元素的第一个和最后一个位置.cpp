/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size();
        int m;
        vector<int> ret = vector<int>(2, -1);
        while(i < j){
            m = (i + j) >> 1;
            if(nums[m] == target){
                i = m;
                j = m;
                while(i >= 0 && nums[i] == target){
                    ret[0] = i--;
                }
                while(j < nums.size() && nums[j] == target){
                    ret[1] = j++;
                }
                return ret;
            }else if(nums[m] < target){
                i = m + 1;
            }else{
                j = m;
            }
        }
        return ret;
    }
};
// @lc code=end

