/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        while(!S.empty()){
            if(ans.empty()){
                ans.push_back(S.back());
                S.pop_back();
            }else{
                if(ans.back() == S.back()){
                    ans.pop_back();
                    S.pop_back();
                }else{
                    ans.push_back(S.back());
                    S.pop_back();
                }
            }
        }

        ans = string(ans.rbegin(), ans.rend());
        return ans;
    }
};
// @lc code=end

