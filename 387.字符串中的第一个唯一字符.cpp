/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include<vector>
#include<hash_map>
using namespace std;
using namespace __gnu_cxx;

class Solution {
public:
    int firstUniqChar(string s) {
        hash_map<char, int> map;
        for(char item:s){
            if(map.count(item)) map[item] = 0;
            else map[item] = 1;
        }

        for(int i = 0; i < s.size(); ++i){
            if(map[s[i]]) return i;
        }

        return -1;
    }
};
// @lc code=end

