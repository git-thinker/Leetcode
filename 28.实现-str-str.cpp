/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.size()) return 0;
        if(needle.size() > haystack.size()) return -1;
        bool flag;
        for(int i = 0; i < haystack.size()- needle.size() + 1; ++i){
            flag = true;
            for(int j = 0; j < needle.size(); ++j){
                if(haystack[i+j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
};
// @lc code=end

