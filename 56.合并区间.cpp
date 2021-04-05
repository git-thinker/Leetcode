/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
bool comp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ret;
        for(int i = 0; i < intervals.size(); i++){
            if(!i || (*--ret.end())[1] < intervals[i][0]){
                ret.emplace_back(vector<int>(intervals[i].begin(), intervals[i].end()));
            }else{
                (*--ret.end())[1] = max(intervals[i][1], (*--ret.end())[1]);
            }
        }
        return ret;
    }
};
// @lc code=end

