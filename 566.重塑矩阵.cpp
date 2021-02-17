/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size()){
            if(nums.size() * nums[0].size() != r * c) return nums;
        }else{
            return nums;
        }
        int x = nums.size();
        int y = nums[0].size();
        int counter = c - 1;
        vector<vector<int>> rst;
        for(int i = 0; i < x; ++i){
            for(int j = 0; j < y; ++j){
                if(counter == 0 || counter == c - 1){
                    rst.push_back(vector<int>());
                    counter = c - 1;
                }
                rst[rst.size()-1].push_back(nums[i][j]);
                counter--;
            }
        }
        return rst;
    }
};

// @lc code=end

