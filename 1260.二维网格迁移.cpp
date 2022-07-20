/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 *
 * [1260] 二维网格迁移
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> vec;
        vector<vector<int>> ret;
        int cnt = grid.size() * grid[0].size();
        // prevent potential underflow problem
        k %= cnt;
        for(auto line: grid){
            for(auto item: line){
                vec.push_back(item);
            }
        }
        for(int i = 0; i < cnt; i++){
            if(i % grid[0].size() == 0){
                ret.push_back(vector<int>());
            }
            ret.back().push_back(vec[(i-k+cnt)%cnt]);
        }
        return ret;
    }
};
// @lc code=end

