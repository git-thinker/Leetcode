/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */
#include<vector>
#include<queue>
#include<map>
using namespace std;
// @lc code=start
class comp_by_profit{
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b){
        if(a.second > b.second) return false;
        if(a.second < b.second) return true;
        if(a.first < b.second) return true;
        else return false;
    }
};

class comp_by_capital{
    public:
        bool operator()(pair<int, int>& a, pair<int, int>& b){
        return (a.first > b.first);
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp_by_capital> capital_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp_by_profit> profit_heap;
        for(int i = 0; i < profits.size(); i++){
            capital_heap.push(pair<int, int>(capital[i], profits[i]));
        }
        while(k > 0){
            while(capital_heap.size() && capital_heap.top().first <= w){
                profit_heap.push(capital_heap.top());
                capital_heap.pop();
            }
            if(profit_heap.size()){
                w += profit_heap.top().second;
                k--;
                profit_heap.pop();
            }else if(capital_heap.size() && capital_heap.top().first > w || capital_heap.size() == 0){
                break;
            }
        }
        return w;
    }
};
// @lc code=end

