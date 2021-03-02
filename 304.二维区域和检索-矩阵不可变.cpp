/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
#include<vector>
using namespace std;
class NumMatrix {
public:
    vector<vector<int>> myMatrix;
    int m, n;
    NumMatrix(vector<vector<int>>& matrix) {
        this->m = matrix.size();
        if(!this->m) return;
        this->n = matrix[0].size();
        for(int i = 0; i < this->m; ++i){
            for(int j = 0; j < this->n; ++j){
                if(i == 0 && j == 0) continue;
                if(i == 0 && j != 0) matrix[i][j] += matrix[i][j-1];
                if(i != 0 && j == 0) matrix[i][j] += matrix[i-1][j];
                if(i != 0 && j != 0) matrix[i][j] += matrix[i][j-1] + matrix[i-1][j] - matrix[i-1][j-1];
            }
        }
        this->myMatrix.assign(matrix.begin(), matrix.end());
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 && col1){
            return this->myMatrix[row2][col2] \
                + this->myMatrix[row1-1][col1-1] \
                - this->myMatrix[row2][col1-1] \
                - this->myMatrix[row1-1][col2];
        }else if(row1 && !col1){
            return this->myMatrix[row2][col2] \
                - this->myMatrix[row1-1][col2];
        }else if(col1 && !row1){
            return this->myMatrix[row2][col2] \
                - this->myMatrix[row2][col1-1];
        }else {
            return this->myMatrix[row2][col2];
        }
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

