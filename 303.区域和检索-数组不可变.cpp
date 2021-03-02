/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include<vector>
using namespace std;

class NumArray {
public:
    vector<int> data;
    NumArray(vector<int>& nums) {
        this->data = nums;
        for(int i = 0; i < nums.size(); i++){
            if(i) this->data[i] += this->data[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return i? this->data[j] - this->data[i-1] : this->data[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

