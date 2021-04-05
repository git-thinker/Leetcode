/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        ret.emplace_back(vector<int>());
        for(int i = 0; i < nums.size(); i++){
            int n = ret.size();
            for(int j = 0; j < n; j++){
                if(!i || nums[i] != nums[i-1] || (nums[i] == nums[i-1] && !ret[j].empty() && ret[j].back() == nums[i])){
                    vector<int> tmp = vector<int>(ret[j].begin(), ret[j].end());
                    tmp.emplace_back(nums[i]);
                    ret.emplace_back(tmp);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

