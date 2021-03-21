/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() < 3) return ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(!i || nums[i] != nums[i-1])
            this->searchForSolution(nums, ret, i);
        }
        return ret;
    }

    void searchForSolution(vector<int>& nums, vector<vector<int>>& ret, int cursor){
        int i = cursor + 1;
        int j = nums.size() - 1;
        while(i < j){
            if(nums[i] + nums[j] + nums[cursor] == 0){
                vector<int> tmp = {nums[cursor], nums[i], nums[j]};
                ret.emplace_back(tmp);
                
                do{
                    i++;
                }while(i < nums.size() && nums[i] == nums[i-1]);

                do{
                    j--;
                }while(j > cursor && nums[j] == nums[j+1]);


            }else if(nums[i] + nums[j] + nums[cursor] < 0) i++;
            else j--;
        }
    }
};
// @lc code=end

