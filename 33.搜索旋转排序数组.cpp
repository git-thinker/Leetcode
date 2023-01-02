/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        int m = i + (j - i) / 2;
        // [i, j)
        while(i <= j){
            m = (i + j) / 2;
            if(nums[i] < nums[j] && (target < nums[i] || target > nums[j])) return -1;
            if(nums[m] == target) return m;
            if(nums[i] <= nums[m]){
                if(nums[i] <= target && target < nums[m]){
                    j = m-1;
                }else{
                    i = m+1;
                }
            }else{
                if(nums[m] < target && target <= nums[j]){
                    i = m+1;
                }else{
                    j = m-1;
                }
            }
        }
        if(nums[m] == target)return m;
        else return -1;
    }
};
// @lc code=end

