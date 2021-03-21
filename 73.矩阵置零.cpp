/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(!matrix.size()) return ;
        set<int> column, row;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(!matrix[i][j]){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(row.count(i) || column.count(j)) matrix[i][j] = 0;
            }
        }
    }
};
// @lc code=end

