/*
 * @lc app=leetcode.cn id=2335 lang=cpp
 *
 * [2335] 装满杯子需要的最短总时长
 */
# include<vector>
# include<queue>
# include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end(), greater<int>());
        if(amount[0] > amount[1] + amount[2]){
            return amount[0];
        }else{
            return amount[0] + (amount[1] + amount[2] - amount[0] + 1) / 2;
        }
    }
};
// @lc code=end

