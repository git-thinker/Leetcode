/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size(); // valid [i, j)
        int m;
        while(i < j){
            m = (i + j) / 2;
            if(nums[m] == target) return m;
            if(nums[m] < target){
                i = m + 1;
                // i to m+1 since m not valid
            }else{
                j = m;
                // j to m since j is not included
            }
        }
        return j;
    }
};
// @lc code=end

