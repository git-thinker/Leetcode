/*
 * @lc app=leetcode.cn id=1228 lang=cpp
 *
 * [1228] 等差数列中缺失的数字
 */

// @lc code=start
int miner(int a, int b){
    if(a > 0 && b > 0) return min(a, b);
    if(a < 0 && b < 0) return max(a, b);
    return 0;
}

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        vector<int> delta;
        int realDelta, i;
        for(i = 0; i < 2; i++){
            delta.push_back(arr[i+1] - arr[i]);
        }

        if(delta[0] != delta[1]){
            realDelta = miner(delta[0], delta[1]);
            for(i = 0; i < 2; i++){
                if(delta[i] != realDelta) break;
            }
            return arr[i] + realDelta;
        }else{
            realDelta = delta[0];
        }

        for(i = 2; i < arr.size() - 1; ++i){
            if(arr[i+1] - arr[i] != realDelta) break;
        }
        return arr[i] + realDelta;
    }
};
// @lc code=end