/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include<string>
#include<hash_map>
using namespace std;
using namespace __gnu_cxx;

class Solution {
public:
    bool isAnagram(string& s, string& t) {
        // if(s.empty() ^ t.empty()) return false;
        // if(s.empty() && s.empty()) return true;
        // auto a = s.find(t[t.size()-1]);
        // if(0 <= a && a < s.size()){
        //     t.pop_back();
        //     s.erase(s.begin()+a);
        //     return isAnagram(s, t);
        // }else{
        //     return false;
        // } 
        
        hash_map<char, int> myMap;
        for(char item: s){
            if(myMap.find(item) != myMap.end()) myMap[item]++;
            else myMap[item] = 1;
        }

        for(char item: t){
            if(myMap.find(item) == myMap.end()) return false;
            else{
                if(myMap[item]) myMap[item]--;
                else return false;
            }
        }

        for(pair<char, int> item: myMap) if(item.second) return false;
        return true;
    }
};
// @lc code=end

