/*
 * @lc app=leetcode.cn id=1624 lang=cpp
 *
 * [1624] 两个相同字符之间的最长子字符串
 */
#include<string>
#include<map>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char, pair<int, int>> counter;
        int ret = -1;
        for(int i = 0; i < s.size(); i++){
            if(counter.find(s[i]) != counter.end()){
                counter[s[i]].first = min(counter[s[i]].first, i);
                counter[s[i]].second = max(counter[s[i]].second, i);
            }else{
                counter[s[i]] = pair<int, int>(i, i);
            }
        }
        for(auto item: counter){
            ret = max(ret, item.second.second - item.second.first - 1);
        }
        return ret;
    }
};
// @lc code=end

