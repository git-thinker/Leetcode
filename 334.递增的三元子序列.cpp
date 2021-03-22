/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
#include<vector>
#define inf 2147483647;
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // vector<int> miner;
        // for(int i = 0; i < nums.size(); ++i){
        //     miner.push_back(0);
        //     for(int j = 0; j < i; ++j){
        //         if(nums[j] < nums[i]){
        //             miner[i] = max(miner[i], miner[j]+1);
        //             if(miner[i] >= 2) return true;
        //         }
        //     }
        // }
        // return false;

        int i = inf;
        int j = inf;
        for(int item: nums){
            if(item > j) return true;
            if(item < i){
                i = item;
            }else if(i < item && item < j){
                j = item;
            }
        }
        return false;
    }
};
// @lc code=end

