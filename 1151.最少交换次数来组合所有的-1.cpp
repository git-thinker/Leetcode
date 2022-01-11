/*
 * @lc app=leetcode.cn id=1151 lang=cpp
 *
 * [1151] 最少交换次数来组合所有的 1
 */
#include <vector>
#include<numeric>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int sum = accumulate(data.begin(), data.end(), 0);
        // [i, j)
        int i = 0, j = sum;
        int ret;
        int cnt = 0;
        for(int f = i; f < j; f++){
            cnt += data[f];
        }
        ret = sum - cnt;
        while(j != data.size()){
            cnt += data[j];
            cnt -= data[i];
            i++; j++;
            if(ret > sum - cnt){
                ret = sum - cnt;
            }
        }
        return ret;


    }
};
// @lc code=end

