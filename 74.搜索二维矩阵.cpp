/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = m * n;
        int mid;
        int x, y;
        while(i < j){
            mid = (i + j) >> 1;
            x = mid / n;
            y = mid % n;
            if(matrix[x][y] == target) return true;
            else if(matrix[x][y] < target) i = mid + 1;
            else j = mid;
        }
        return false;
    }
};
// @lc code=end

