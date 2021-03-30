/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include<vector>
#include<queue>
#include<map>
using namespace std;

template <typename T> class comp{
    public:
    bool operator()(T& a, T& b){
        return a.second < b.second ? true : false;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> myMap;
        vector<int> ret;
        priority_queue<pair<int, int>, deque<pair<int, int>>, comp<pair<int, int>>> myQueue;
        for(auto i: nums){
            auto item = myMap.find(i);
            if(item == myMap.end()){
                myMap[i] = 1;
            }else{
                item->second++;
            }
        }
        for(auto item: myMap) myQueue.push(item);
        for(int i = 0; i < k; i++){
            ret.emplace_back(myQueue.top().first);
            myQueue.pop();
        }
        return ret;
    }
};
// @lc code=end

