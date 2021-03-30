/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> added = vector<bool>(nums.size(), true);
        vector<vector<int>> ret;
        vector<int> tmp;
        generate(added, tmp, ret, nums);
        return ret;
    }

    void generate(vector<bool>& added, vector<int>& tmp, vector<vector<int>>& ret, vector<int>& nums){
        if(added.size() == tmp.size()){
            ret.emplace_back(vector<int>(tmp.begin(), tmp.end()));
            return ;
        }
        for(int i = 0; i < added.size(); i++){
            if(added[i]){
                added[i] = false;
                tmp.emplace_back(nums[i]);
                generate(added, tmp, ret, nums);
                tmp.pop_back();
                added[i] = true;
            }
        }
    }
};
// @lc code=end

