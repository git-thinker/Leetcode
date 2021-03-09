/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int passon = 1;
        for(auto iter = digits.rbegin(); iter != digits.rend(); iter++){
            if(!passon) break;
            *iter += passon;
            passon = *iter / 10;
            *iter %= 10;
        }

        if(passon) digits.insert(digits.begin(), passon);
        return digits;
    }
};
// @lc code=end

