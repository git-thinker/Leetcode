/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix = vector<vector<int>>(m, vector<int>(n, 0));
        int i, j;
        for(i = 0, j = 0; i < m; i++){
            matrix[i][j] = 1;
        }
        for(i = 0, j = 0; j < n; j++){
            matrix[i][j] = 1;
        }
        for(i = 1; i < m; i++){
            for(j = 1; j < n; j++){
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
        return matrix.back().back();
    }
};
// @lc code=end

