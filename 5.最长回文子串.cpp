/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int rst_i = 0;
        int rst_k = 1;
        int fullSize = s.size();
        vector<vector<bool>> statusMatrix(fullSize, vector<bool>(s.size(), false));
        for(int i = 0; i < fullSize; ++i){
            statusMatrix[i][i] = true;
            if(i + 1 < fullSize && s[i] == s[i+1]){
                statusMatrix[i][i+1] = true;
                if(rst_k < 2) {
                    rst_i = i;
                    rst_k = 2;
                }
            }
        }
        for(int k = 3; k <= fullSize; k++){
            for(int i = 0; i + k - 1 < fullSize; i++){
                // [i, i + k + 1]
                statusMatrix[i][i+k-1] = statusMatrix[i+1][i+k-2] && s[i] == s[i+k-1];
                if(statusMatrix[i][i+k-1] && rst_k < k){
                    rst_i = i;
                    rst_k = k;
                }
            }
        }
        return s.substr(rst_i, rst_k);                
    }
};
// @lc code=end