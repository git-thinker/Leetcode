/*
 * @lc app=leetcode.cn id=1743 lang=cpp
 *
 * [1743] 从相邻元素对还原数组
 */
#include<vector>
#include<map>
#include<set>
using namespace std;
// @lc code=start
class Solution {
public:
    void updateMyMap(map<int, set<int>>& myMap, int a, int b){
        if(myMap.find(a) == myMap.end()){
            set<int> tmpSet;
            tmpSet.insert(b);
            myMap[a] = tmpSet;
        }else{
            myMap[a].insert(b);
        }

        if(myMap.find(b) == myMap.end()){
            set<int> tmpSet;
            tmpSet.insert(a);
            myMap[b] = tmpSet;
        }else{
            myMap[b].insert(a);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, set<int>> myMap;
        vector<int> ret;

        for(auto item: adjacentPairs){
            updateMyMap(myMap, item[0], item[1]);
        }

        int prev, current;
        for(auto item: myMap){
            if(item.second.size() == 1){
                prev = item.first;
                current = *(item.second.begin());
                break;
            }
        }

        // main loop
        while(1){
            ret.push_back(prev);
            myMap.erase(myMap.find(prev));
            if(!myMap.size()) break;
            myMap[current].erase(myMap[current].find(prev));
            prev = current;
            current = *(myMap[current].begin());
        }

        return ret;
    }
};
// @lc code=end

