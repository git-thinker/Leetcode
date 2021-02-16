/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int tmpAns = 0;
        for(auto i: nums){
            if(i) tmpAns += 1;
            if(!i){
                ans = max(ans, tmpAns);
                tmpAns = 0;
            }
        }
        ans = max(ans, tmpAns);
        return ans;
    }
};
// @lc code=end

