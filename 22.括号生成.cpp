/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        string myStr;
        vector<string> ret;
        generate(myStr, n, n, ret);
        return ret;
    }

    bool valid(string& str){
        int n = 0;
        for(char item: str){
            if(item == '(') n++;
            else n--;
            if(n < 0) return false;
        }
        return n == 0;
    }

    void generate(string& str, int left, int right, vector<string>& ret){
        if(!left && !right && valid(str)) ret.emplace_back(string(str.begin(), str.end()));
        if(left){
            str.push_back('(');
            generate(str, left-1, right, ret);
            str.pop_back();
        }
        if(right){
            str.push_back(')');
            generate(str, left, right-1, ret);
            str.pop_back();
        }
    }
};
// @lc code=end

