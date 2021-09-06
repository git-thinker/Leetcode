/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include<string>
#include<map>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0;
        int ret_i = 0, ret_j = s.size();
        map<char, int> requirement;
        map<char, int> status;
        for(char item: t){
            requirement[item]++;
        }

        for(char item: t){
            status[item] = 0;
        }

        while(j <= s.size()){
            if(check(requirement, status)){
                if(ret_j - ret_i > j - i){
                    ret_i = i;
                    ret_j = j;
                }
                status[s[i]]--;
                i++;
            }else{
                status[s[j]]++;
                j++;
            }
        }

        if(i == 0 && j == s.size()+1 && ret_i ==0 && ret_j == s.size()){
            if(check(requirement, status)){
                ret_i = i;
                ret_j = j;
            }else{
                ret_i = 0;
                ret_j = 0;
            }
        }else{
            if(check(requirement, status)){
                ret_i = i;
                ret_j = j;
            }
        }
        return s.substr(ret_i, ret_j - ret_i);
    }

    bool check(map<char, int>& requirement, map<char, int>& status){
        for(auto item: requirement){
            if(status[item.first] < item.second){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

