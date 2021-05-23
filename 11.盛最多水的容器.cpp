/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int i = 0, j = height.size() - 1;
        while(i < j){
            if(ret < (j - i) * min(height[i], height[j])){
                ret = (j - i) * min(height[i], height[j]);
            }
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return ret;
    }
};
// @lc code=end

