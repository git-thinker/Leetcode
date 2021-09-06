/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
#include<vector>
#include<set>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> mySet;k++;
        if(k > nums.size()){
            k = nums.size();
        }
        for(int i = 0; i < k; i++){
            mySet.insert(nums[i]);
        }
        if(mySet.size() < k) return true;
        for(int i = 0; i < nums.size() - k; i++){
            mySet.erase(nums[i]);
            if(mySet.find(nums[i+k]) == mySet.end()){
                mySet.insert(nums[i+k]);
            }else{
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

