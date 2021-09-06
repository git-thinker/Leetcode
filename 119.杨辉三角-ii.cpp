/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1);
        for(double i = 1; i <= rowIndex; i++){
            row.push_back(1LL * row.back() *(rowIndex - i + 1) / i);
        }
        return row;
    }
};
// @lc code=end

