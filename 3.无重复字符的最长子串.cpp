/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int min = 0;
        map<char, int> stored;
        int i = 0, j = 0;
        // valid segment [i,j)
        while(j < s.size()){
            if(stored.find(s[j]) == stored.end()){
                // next char ok to be added
                stored[s[j]] = j;
                j++;
            }else{
                stored.erase(stored.find(s[i]));
                i++;
            }
            if(min < j - i) min = j - i;
        }
        return min;
    }
};
// @lc code=end

