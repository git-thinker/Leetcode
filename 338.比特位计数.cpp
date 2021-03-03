/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        int maxOne = 0;
        vector<int> ans = {0};
        for(int i = 1; i<= num; ++i){
            if((i & (i-1)) == 0){
                maxOne = i;
            }
            ans.push_back(ans[i - maxOne] + 1);
        }
        return ans;
    }
};
// @lc code=end

