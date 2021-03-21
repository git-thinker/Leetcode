/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; ++i){
            for(int j = 0; j < n ; ++j){
                this->swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                this->swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// @lc code=end

