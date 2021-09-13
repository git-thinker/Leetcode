/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        bool flag = false;
        // start detecting word?
        for(int i = s.size() - 1; i >= 0; i--){
            if(flag){
                if(s[i] == ' '){
                    break;
                }else{
                    ret++;
                }
            }else{
                if(s[i] == ' '){
                    continue;
                }else{
                    flag = true;
                    ret++;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

