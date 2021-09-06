/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size();
        int m;
        while(i < j){
            m = (i + j) / 2;
            if(nums[m] == target) return m;
            if(nums[m] > target) j = m;
            else i = m + 1;
        }return -1;
    }
};
// @lc code=end

