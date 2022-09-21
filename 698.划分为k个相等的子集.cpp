/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */
#include<vector>
#include<numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) return false;
        sum /= k;
        vector<int> buckets = vector<int>(k,0);
        return recursive(nums, k, sum, buckets, 0);
    }

    bool recursive(vector<int>& nums, int k, int sum, vector<int>& buckets, int cursor){
        if(cursor == nums.size()){
            for(int i = 0; i < k; i++){
                if(buckets[i] != sum) return false;
            }
            return true;
        }
        for(int i = 0; i < k; i++){
            if(buckets[i] + nums[cursor]> sum || (i && buckets[i] == buckets[i-1])) continue;
            buckets[i] += nums[cursor];
            if(recursive(nums, k, sum, buckets, cursor+1)) return true;
            buckets[i] -= nums[cursor];
        }
        return false;
    }
};
// @lc code=end

