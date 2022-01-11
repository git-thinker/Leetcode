/*
 * @lc app=leetcode.cn id=2134 lang=cpp
 *
 * [2134] 最少交换次数来组合所有的 1 II
 */
#include <vector>
#include<numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // [i, j)
        int i = 0, j = sum;
        int ret;
        int cnt = 0;
        for(int f = i; f < j; f++){
            cnt += nums[f];
        }
        if(sum == 0){
            return 0;
        }
        ret = sum - cnt;
        while(true){
            if(i == nums.size()){
                i = 0;
            }
            if(j == nums.size()){
                j = 0;
            }
            cnt += nums[j];
            cnt -= nums[i];
            i++; j++;
            if(ret > sum - cnt){
                ret = sum - cnt;
            }
            if(j == sum){
                break;
            }
        }
        return ret;
    }
};
// @lc code=end

