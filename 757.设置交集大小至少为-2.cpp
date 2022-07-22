/*
 * @lc app=leetcode.cn id=757 lang=cpp
 *
 * [757] 设置交集大小至少为2
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class comp{
    public:
    bool operator()(vector<int> a, vector<int> b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
};
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int ans = 2;
        sort(intervals.begin(), intervals.end(), comp());
        // interval[][0] descending
        // interval[][1] ascending
        // 0              |^^--------|
        // 1              |---------------|
        // 2      |-----|
        // 3      |----------|
        // 4   |----------|
        // greedily take first two available elements

        int j = intervals[0][0];
        int k = intervals[0][0]+1;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][1] >= k){
                // fully contained by previous
                // do nothing
                continue;
            }else if(j <= intervals[i][1] && intervals[i][1] < k){
                ans++;
                k = j;
                j = intervals[i][0];
            }else{
                ans += 2;
                j = intervals[i][0];
                k = intervals[i][0] + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

