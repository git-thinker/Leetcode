/*
 * @lc app=leetcode.cn id=854 lang=cpp
 *
 * [854] 相似度为 K 的字符串
 */
#include<string>
#include<queue>
#include<unordered_set>
#include<unordered_map>
using namespace std;
using namespace __gnu_cxx;
// @lc code=start
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        unordered_set<string> set;
        queue<pair<string, int>> q;
        q.push(pair<string, int>(s1, 0));
        int step = 0;
        int pos_cache = 0;
        while(!q.empty()){
            int round = q.size();
            for(int _ = 0; _ < round; _++){
                string str = q.front().first;
                int pos = q.front().second;
                q.pop();
                if(str == s2) return step;
                while(pos+1 < str.size() && str[pos] == s2[pos]) pos++;
                for(int i = pos + 1; i < str.size(); i++){
                    if(str[pos] == str[i] || str[i] != s2[pos]) continue;
                    swap(str[pos], str[i]);
                    if(set.find(str) == set.end()){
                        set.insert(str);
                        q.push(pair<string, int>(str, pos + 1));
                    }
                    swap(str[pos], str[i]);
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

