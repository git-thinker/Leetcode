/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.emplace_back(vector<int>());
        for(int num: nums){
            int size = ret.size();
            for(int i = 0; i < size; i++){
                auto item = vector<int>(ret[i].begin(), ret[i].end());
                item.emplace_back(num);
                ret.emplace_back(item);
            }
        }
        return ret;
    }
};
// @lc code=end

