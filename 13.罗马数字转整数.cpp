/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include<map>
#include<string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
        int ans;
        for(int i = 0; i < s.size(); i++){
            if(i == s.size()-1|| i != s.size()-1 && dict[s[i]] >= dict[s[i+1]]){
                ans += dict[s[i]];
            }else{
                ans += dict[s[i+1]] - dict[s[i]];
                i++;
            }
        }
        return ans;  
    }
};
// @lc code=end

