/*
 * @lc app=leetcode.cn id=2351 lang=cpp
 *
 * [2351] 第一个出现两次的字母
 */
#include<string>
#include<set>
using namespace std;
// @lc code=start
class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> log;
        for(int i=0; i<s.size(); i++){
            if(log.find(s[i]) == log.end()){
                log.insert(s[i]);
            }else{
                return s[i];
            }
        }
        return ' ';
    }
};
// @lc code=end

