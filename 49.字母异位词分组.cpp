/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> index;
        vector<vector<string>> ret;
        for(auto &str: strs){
            int targetIndex;
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            if(index.count(sortedStr)){
                targetIndex = index[sortedStr];
            }else{
                targetIndex = ret.size();
                index[sortedStr] = targetIndex;
                ret.emplace_back(vector<string>());
            }
            ret[targetIndex].emplace_back(str);
        }
        return ret;
    }
};
// @lc code=end

