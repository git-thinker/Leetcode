/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        int i = 0;
        while(1){
            for(int j = 0; j < strs.size(); ++j){
                if(i >= strs[j].size() || strs[0][i] != strs[j][i]) return strs[0].substr(0, i);
            }
            i++;
        }
        return "";
    }
};
// @lc code=end

