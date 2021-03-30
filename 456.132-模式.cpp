/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */

// @lc code=start
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<pair<int, int>> bounder;
        int lower = nums[0];
        int upper;
        bool flag = true;
        for(int i = 0; i < nums.size(); i++){
                if(nums[i] < lower){
                    lower = nums[i];
                    flag = true;
                }else if(nums[i] > lower && flag){
                    flag = false;
                    upper = nums[i];
                    bounder.emplace_back(pair<int, int>(lower, upper));
                }
            
                for(auto& cursorPair: bounder){
                    if(cursorPair.first < nums[i] && nums[i] < cursorPair.second){
                        return true;
                    }else if(nums[i] > cursorPair.second){
                        cursorPair.second = nums[i];
                    }
                }
        }
        return false;
    }
};
// @lc code=end

