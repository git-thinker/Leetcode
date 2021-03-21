/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
#include<cstdlib>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> myVec;
    Solution(vector<int>& nums) {
        myVec = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return myVec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> rst = vector<int>(myVec.begin(), myVec.end());
        for(int i = 0; i < rst.size(); i++){
            int j = rand() % rst.size();
            this->swap(rst[i], rst[j]);
        }
        return rst;
    }

    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

