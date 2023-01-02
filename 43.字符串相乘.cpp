/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
int getNum(char c){
    return c - '0';
}
char getChar(int i){
    return i + '0';
}
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ret_vec = vector<int>(num1.size()+num2.size(), 0);
        string ret;
        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size(); j++){
                ret_vec[ret_vec.size()-1-i-j] += getNum(num1[num1.size()-1-i]) * getNum(num2[num2.size()-1-j]);
            }
        }
        int acc = 0;
        for(int i = ret_vec.size() - 1; i >= 0; i--){
            acc += ret_vec[i];
            ret.push_back(getChar(acc % 10));
            acc /= 10;
        }
        auto cursor = ret.rbegin();
        while(cursor != --ret.rend() && *cursor == '0'){
            cursor++;
        }
        return string(cursor, ret.rend());
    }
};
// @lc code=end

