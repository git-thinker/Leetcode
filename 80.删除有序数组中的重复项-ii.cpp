/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, n = 0;
        while(j < nums.size()){
            if(i < 2){
                nums[i++] = nums[j++];
                n++;
            }else{
                if(nums[i-1] != nums[j] || nums[i-1] == nums[j] && nums[i-2] != nums[j]){
                    nums[i++] = nums[j++];
                    n++;
                }else{
                    j++;
                }
            }
        }
        return n;
    }
};
// @lc code=end

