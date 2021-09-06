/*
 * @lc app=leetcode.cn id=1893 lang=cpp
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), comp);
        if(left < ranges.front().front()) return false;
        int cursor = left;
        auto periodcursor = ranges.begin();
        while(cursor <= right && periodcursor != ranges.end()){
            if(periodcursor->front() <= cursor && cursor <= periodcursor->back()){
                cursor = max(cursor, periodcursor->back() + 1);
            }
            periodcursor++;
        }

        return cursor > right;
    }
};
// @lc code=end

