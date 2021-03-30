/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index[3] = {0, 0, 0};
        for(auto& i: nums){
            index[i]++;
        }
        for(auto& i: nums){
            for(int item = 0; item < 3; item++){
                if(index[item]){
                    index[item]--;
                    i = item;
                    break;
                }
            }
        }
    }
};
// @lc code=end

