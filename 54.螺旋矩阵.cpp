/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int i=0, j=0;
        int m=matrix.size(), n=matrix[0].size();
        int x=0, y=0;
        while(ans.size() < matrix.size()*matrix[0].size()){
            i=x;
            j=y;
            for(; j < n; ++j){
                ans.push_back(matrix[i][j]);
            }
            j--;
            i++;
            x++;
            for(; i < m; ++i){
                ans.push_back(matrix[i][j]);
            }
            i--;
            j--;
            n--;
            for(; j >= y; --j){
                ans.push_back(matrix[i][j]);
            }
            j++;
            i--;
            m--;
            for(; i >= x; --i){
                ans.push_back(matrix[i][j]);
            }
            i++;
            j++;
            y++;
        }
        while(ans.size() != matrix.size()*matrix[0].size()) ans.pop_back();
        return ans;
    }
};

// @lc code=end

