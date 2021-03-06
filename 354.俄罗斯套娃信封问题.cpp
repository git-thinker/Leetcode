/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b){
        if(a[0] > b[0]) return true;
        if(a[0] < b[0]) return false;
        if(a[1] >= b[1]) return true;
        return false;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        int ans = 0;
        vector<int> dynamicAns;
        for(int i = 0; i < envelopes.size(); ++i){
            dynamicAns.emplace_back(0);
            for(int j = 0; j < i; ++j){
                if(envelopes[j][0] > envelopes[i][0] && envelopes[j][1] > envelopes[i][1] && dynamicAns[j] > dynamicAns.back()){
                    dynamicAns.back() = dynamicAns[j];
                }
            }
            dynamicAns.back()++;
            if(dynamicAns.back() > ans){
                ans = dynamicAns.back();
            }
        }
        return ans;
    }
};
// @lc code=end

