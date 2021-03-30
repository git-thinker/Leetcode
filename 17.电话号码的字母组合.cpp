/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    map<char, string> myMap;
    vector<string> ret;
    string tmp;
    vector<string> letterCombinations(string digits) {
        myMap['2'] = "abc";
        myMap['3'] = "def";
        myMap['4'] = "ghi";
        myMap['5'] = "jkl";
        myMap['6'] = "mno";
        myMap['7'] = "pqrs";
        myMap['8'] = "tuv";
        myMap['9'] = "wxyz";
        if(digits.size())recursive(digits, 0);
        return ret;
    }

    void recursive(string &digits, int i){
        // i is the first valid position to be added
        if(i == digits.size()){
            string done = string(tmp.begin(), tmp.end());
            ret.emplace_back(done);
            return;
        }
        for(char nextChar: myMap[digits[i]]){
            tmp.push_back(nextChar);
            recursive(digits, i+1);
            tmp.pop_back();
        }
    }
};
// @lc code=end

