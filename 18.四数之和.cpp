/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        if(nums.size() < 4) return ret;
        for(int i = 0; i < nums.size() - 3; i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < nums.size() - 2; j++){
                if(j != i + 1 && nums[j] == nums[j-1]) continue;
                int p = j + 1;
                int q = nums.size() - 1;
                int tmp_target = target - nums[i] - nums[j];
                while(p < q){
                    if(nums[p] + nums[q] > tmp_target){
                        q--;
                    }else if(nums[p] + nums[q] < tmp_target){
                        p++;
                    }else{
                        vector<int> tmp = {nums[i], nums[j], nums[p], nums[q]};
                        ret.push_back(tmp);
                        do{
                            p++;
                        }while(p < nums.size() && nums[p] == nums[p-1]);
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end

