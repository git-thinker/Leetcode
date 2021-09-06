/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> prev_row;
        vector<int> row;
        for(int i = 0; i < numRows; i++){
            if(!i){
                prev_row.clear();
                row.clear();
                row.push_back(1);
            }else{
                row.clear();
                row.push_back(1);
                for(int j = 0; j < prev_row.size() - 1; j++){
                    row.push_back(prev_row[j] + prev_row[j+1]);
                }
                row.push_back(1);
            }
            ret.push_back(row);
            prev_row = row;
        }
        return ret;
    }
};
// @lc code=end

