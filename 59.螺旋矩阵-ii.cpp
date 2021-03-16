/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret = vector<vector<int>>(n, vector<int>(n, -1));
        int item = 1;
        int i = 0, j = 0, x = n, y = n;
        int cursor0 = 0, cursor1 = 0;
        while(item <= n * n){
            for(; cursor1 < y; cursor1++){
                ret[cursor0][cursor1] = item++;
            }
            i++, cursor1--, cursor0++;
            for(; cursor0 < x; cursor0++){
                ret[cursor0][cursor1] = item++;
            }
            y--, cursor0--, cursor1--;
            for(; j <= cursor1; cursor1--){
                ret[cursor0][cursor1] = item++;
            }
            x--, cursor1++, cursor0--;
            for(; i <= cursor0; cursor0--){
                ret[cursor0][cursor1] = item++;
            }
            j++, cursor0++, cursor1++;
        }    
        return ret;
    }
};
// @lc code=end

