/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
# include<vector>
using namespace std;
class Solution {
public:
    // vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    //     vector<vector<int>> rst;
    //     for(auto line: A){
    //         vector<int> tmp;
    //         if(line.size() > 0){
    //             for(auto cursor = --line.end(); cursor >= line.begin(); cursor--){
    //                 tmp.push_back(1 - *cursor);
    //             }
    //         }
    //         rst.push_back(tmp);
    //     }
    //     return rst;
    // }

     vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int tmp;
        for(auto &line: A){
            if(line.size() > 0){
                auto i = line.begin();
                auto j = --line.end();   
                while(i < j){
                    tmp = 1 - *i;
                    *i = 1 - *j;
                    *j = tmp;

                    i++;
                    j--;
                }
                if(i == j){
                    *i = 1 - *i;
                }
            }
        }
        return A;
    }
};
// @lc code=end

