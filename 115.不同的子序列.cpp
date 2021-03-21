/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
#include<string>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.empty()) return 1;
        if(s.empty()) return 0;
        int m = s.size();
        int n = t.size();
        // dynamic alaysise
        vector<vector<long>> matrix;
        for(int i = 0; i < s.size(); i++){
            matrix.emplace_back(vector<long>(n, 0));
            for(int j = 0; j < t.size(); j++){
                if(i){
                    matrix[i][j] = matrix[i-1][j];
                    if(s[i] == t[j]){
                        // if this char is in j spot of template
                        // it makes those have (j-1) in proceeded to have j
                        if(j) matrix[i][j] += matrix[i-1][j-1];
                        else matrix[i][j]++;
                    }
                }else{
                    if(!j && s[i] == t[j]){
                        matrix[i][j]++;
                    }
                }
            }
        }
        return matrix[m-1][n-1];
    }

    // int numDistinct(string s, string t) {
    //     if(t.empty()) return 1;
    //     if(s.empty()) return 0;
    //     int m = s.size();
    //     int n = t.size();
    //     // reserve mem using deque
    //     // pop previous one when it is used
    //     deque<vector<long>> matrix;
    //     for(int i = 0; i < s.size(); i++){
    //         matrix.emplace_back(vector<long>(n, 0));
    //         for(int j = 0; j < t.size(); j++){
    //             if(i){
    //                 (*matrix.rbegin())[j] = (*matrix.begin())[j];
    //                 if(s[i] == t[j]){
    //                     if(j) (*matrix.rbegin())[j] += (*matrix.begin())[j-1];
    //                     else (*matrix.rbegin())[j]++;
    //                 }
    //             }else{
    //                 if(!j && s[i] == t[j]){
    //                     (*matrix.rbegin())[j]++;
    //                 }
    //             }
    //         }
    //         if(i) matrix.pop_front();
    //     }
    //     return (*matrix.rbegin())[n-1];
    // }
};
// @lc code=end

